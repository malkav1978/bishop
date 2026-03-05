#include <prometheus/counter.hpp>

#include <gtest/gtest.h>

TEST(PrometheusCounter, init)
{
	prometheus::Counter counter;

	ASSERT_DOUBLE_EQ(counter.getvalue(), 0);
}

TEST(PrometheusCounter, single_increment)
{
	prometheus::Counter counter;

	counter.inc();
	ASSERT_DOUBLE_EQ(counter.getvalue(), 1);
}

TEST(PrometheusCounter, multi_increment)
{
	prometheus::Counter counter;

	counter.inc();
	counter.inc(40);
	counter.inc(0.2);
	ASSERT_DOUBLE_EQ(counter.getvalue(), 41.2);
}

TEST(PrometheusCounter, zero_increment)
{
	prometheus::Counter counter;

	counter.inc(42);
	ASSERT_DOUBLE_EQ(counter.getvalue(), 42);
	counter.inc(0);
	ASSERT_DOUBLE_EQ(counter.getvalue(), 42);
}

TEST(PrometheusCounter, negative_increment)
{
	prometheus::Counter counter;

	ASSERT_THROW(counter.inc(-42), std::invalid_argument);
}

TEST(PrometheusCounter, reset)
{
	prometheus::Counter counter;

	counter.inc(42);
	ASSERT_DOUBLE_EQ(counter.getvalue(), 42);
	counter.reset();
	ASSERT_DOUBLE_EQ(counter.getvalue(), 0);
}
