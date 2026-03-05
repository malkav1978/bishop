#pragma once

namespace prometheus
{
	/**
	 * @brief Provides a gauge that can go up and down.
	 * @see https://prometheus.io/docs/instrumenting/writing_clientlibs/#gauge
	 */
	class Gauge
	{
	public:
		Gauge& operator++();
		Gauge operator++(int);
		Gauge& operator+=(double amount);

		Gauge& operator--();
		Gauge operator--(int);
		Gauge& operator-=(double amount);

		void inc(double amount = 1);
		void dec(double amount = 1);
		void set(double value);
		void reset();

		double getvalue() const;

	private:
		double m_value = 0;
	};
}
