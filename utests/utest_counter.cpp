#include <prometheus/metric.hpp>
#include <prometheus/counter.hpp>

#include <gtest/gtest.h>

TEST(PrometheusCounter, init)
{
	prometheus::Counter counter("counter", "Basic counter metric");

	ASSERT_DOUBLE_EQ(counter.value(), 0);
}

TEST(PrometheusCounter, single_increment)
{
	prometheus::Counter counter("counter", "Basic counter metric");

	counter.inc();
	ASSERT_DOUBLE_EQ(counter.value(), 1);
}

TEST(PrometheusCounter, multi_increment)
{
	prometheus::Counter counter("counter", "Basic counter metric");

	counter.inc();
	counter.inc(40);
	counter.inc();
	ASSERT_DOUBLE_EQ(counter.value(), 42);
}

TEST(PrometheusCounter, reset)
{
	prometheus::Counter counter("counter", "Basic counter metric");

	counter.inc(42);
	ASSERT_DOUBLE_EQ(counter.value(), 42);
	counter.reset();
	ASSERT_DOUBLE_EQ(counter.value(), 0);
}

TEST(PrometheusCounter, negative_increment)
{
	prometheus::Counter counter("counter", "Basic counter metric");

	ASSERT_THROW(counter.inc(-42), std::invalid_argument);
}
