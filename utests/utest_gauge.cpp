#include <prometheus/gauge.hpp>

#include <gtest/gtest.h>

TEST(PrometheusGauge, init)
{
	prometheus::Gauge gauge;

	ASSERT_DOUBLE_EQ(gauge.getvalue(), 0);
}

TEST(PrometheusGauge, single_increment)
{
	prometheus::Gauge gauge;

	gauge.inc();
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 1);
}

TEST(PrometheusGauge, multi_increment)
{
	prometheus::Gauge gauge;

	gauge.inc();
	gauge.inc(40);
	gauge.inc(0.2);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 41.2);

	gauge.dec();
	gauge.dec(10);
	gauge.dec(0.5);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 29.7);
}

TEST(PrometheusGauge, zero_increment)
{
	prometheus::Gauge gauge;

	gauge.inc(42);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 42);
	gauge.inc(0);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 42);

	gauge.dec(2);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 40);
	gauge.inc(0);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 40);
}

TEST(PrometheusGauge, reset)
{
	prometheus::Gauge gauge;

	gauge.set(42);
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 42);
	gauge.reset();
	ASSERT_DOUBLE_EQ(gauge.getvalue(), 0);
}
