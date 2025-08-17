#include <prometheus/label.hpp>

#include <gtest/gtest.h>

TEST(PrometheusLabel, initialize)
{
	const prometheus::Label label("label_answer", "42");
	ASSERT_EQ(label.name(), "label_answer");
	ASSERT_EQ(label.value(), "42");
}

TEST(PrometheusLabel, copy)
{
	const prometheus::Label label("label_answer", "42");
	const prometheus::Label clone(label);
	ASSERT_EQ(label.name(), clone.name());
	ASSERT_EQ(label.value(), clone.value());
}

TEST(PrometheusLabel, move)
{
	prometheus::Label label("label_answer", "42");
	const prometheus::Label other(std::move(label));
	ASSERT_TRUE(label.name().empty());
	ASSERT_TRUE(label.value().empty());
	ASSERT_EQ(other.name(), "label_answer");
	ASSERT_EQ(other.value(), "42");
}

TEST(PrometheusLabel, reservedLabel)
{
	ASSERT_THROW(prometheus::Label label("__reserved_label", {}), std::invalid_argument);
}


TEST(PrometheusLabel, invalidLabel)
{
	ASSERT_THROW(prometheus::Label label("000-invalid", {}), std::invalid_argument);
}
