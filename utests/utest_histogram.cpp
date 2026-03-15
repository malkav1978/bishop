#include <prometheus/type.hpp>
#include <prometheus/histogram.hpp>

#include <gtest/gtest.h>

#include <limits>
#include <stdexcept>

TEST(Histogram, DefaultConstructor_IsEmpty)
{
	prometheus::Histogram histogram;
	EXPECT_EQ(histogram.getCount(), 0u);
	EXPECT_DOUBLE_EQ(histogram.getSum(), 0.0);
	EXPECT_TRUE(histogram.getvalues().empty());
}

TEST(Histogram, Constructor_AlwaysAddsInfBucket)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	const auto& buckets = histogram.getvalues();

	ASSERT_FALSE(buckets.empty());
	EXPECT_DOUBLE_EQ(buckets.back().first, std::numeric_limits<double>::infinity());
}

TEST(Histogram, Constructor_BucketsAreSorted)
{
	prometheus::Histogram histogram({ 10.0, 1.0, 5.0 });
	const auto& buckets = histogram.getvalues();

	for (std::size_t i = 1; i < buckets.size(); ++i)
	{
		EXPECT_LT(buckets[i - 1].first, buckets[i].first);
	}
}

TEST(Histogram, Constructor_BucketCountIsInputPlusInf)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	EXPECT_EQ(histogram.getvalues().size(), 4u);
}

TEST(Histogram, Constructor_AllCountsInitializedToZero)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	for (const auto& [bound, count] : histogram.getvalues())
	{
		EXPECT_EQ(count, 0u);
	}
}

TEST(Histogram, Observe_IncreasesCount)
{
	prometheus::Histogram histogram({ 1.0, 5.0 });
	histogram.observe(0.5);
	histogram.observe(3.0);
	EXPECT_EQ(histogram.getCount(), 2u);
}

TEST(Histogram, Observe_AccumulatesSum)
{
	prometheus::Histogram histogram({ 10.0 });
	histogram.observe(2.5);
	histogram.observe(4.5);
	EXPECT_DOUBLE_EQ(histogram.getSum(), 7.0);
}

TEST(Histogram, Observe_NegativeValue)
{
	prometheus::Histogram histogram({ 0.0, 5.0 });
	histogram.observe(-3.0);
	EXPECT_EQ(histogram.getCount(), 1u);
	EXPECT_DOUBLE_EQ(histogram.getSum(), -3.0);
}

TEST(Histogram, Observe_ZeroValue)
{
	prometheus::Histogram histogram({ 0.0, 5.0 });
	histogram.observe(0.0);
	EXPECT_EQ(histogram.getCount(), 1u);
	EXPECT_DOUBLE_EQ(histogram.getSum(), 0.0);
}

TEST(Histogram, Observe_ValueBelowAllBounds_IncrementsAllBuckets)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	histogram.observe(0.5);

	for (const auto& [bound, count] : histogram.getvalues())
	{
		EXPECT_EQ(count, 1u) << "bound=" << bound;
	}
}

TEST(Histogram, Observe_ValueAboveAllBounds_OnlyInfBucketIncremented)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	histogram.observe(99.0);

	const auto& buckets = histogram.getvalues();
	for (std::size_t i = 0; i < buckets.size() - 1; ++i)
	{
		EXPECT_EQ(buckets[i].second, 0u) << "bound=" << buckets[i].first;
	}

	EXPECT_EQ(buckets.back().second, 1u);
}

TEST(Histogram, Observe_ValueExactlyOnBound_BucketIsIncremented)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	histogram.observe(5.0);

	const auto& buckets = histogram.getvalues();
	EXPECT_EQ(buckets[0].second, 0u);
	EXPECT_EQ(buckets[1].second, 1u);
	EXPECT_EQ(buckets[2].second, 1u);
	EXPECT_EQ(buckets[3].second, 1u);
}

TEST(Histogram, Observe_CumulativeSemantics_MultipleValues)
{
	prometheus::Histogram histogram({ 1.0, 5.0, 10.0 });
	histogram.observe(0.5);
	histogram.observe(3.0);
	histogram.observe(7.0);
	histogram.observe(20.0);

	const auto& buckets = histogram.getvalues();
	EXPECT_EQ(buckets[0].second, 1u);
	EXPECT_EQ(buckets[1].second, 2u);
	EXPECT_EQ(buckets[2].second, 3u);
	EXPECT_EQ(buckets[3].second, 4u);
}

TEST(Histogram, Observe_InfinityValue_OnlyInfBucketIncremented)
{
	prometheus::Histogram histogram({ 1.0, 5.0 });
	histogram.observe(std::numeric_limits<double>::infinity());

	const auto& buckets = histogram.getvalues();
	EXPECT_EQ(buckets[0].second, 0u);
	EXPECT_EQ(buckets[1].second, 0u);
	EXPECT_EQ(buckets[2].second, 1u);
}

TEST(Histogram, Observe_ManyObservations_SumAndCountCorrect)
{
	prometheus::Histogram histogram({ 10.0 });
	constexpr int N = 1000;
	for (int i = 1; i <= N; ++i)
	{
		histogram.observe(static_cast<double>(i));
	}

	EXPECT_EQ(histogram.getCount(), static_cast<std::size_t>(N));
	EXPECT_DOUBLE_EQ(histogram.getSum(), static_cast<double>(N * (N + 1) / 2));
}
