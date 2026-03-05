#pragma once

namespace prometheus
{
	/**
	 * @brief Provides a monotonically increasing counter.
	 * @see https://prometheus.io/docs/instrumenting/writing_clientlibs/#counter
	 */
	class Counter
	{
	public:
		Counter& operator++();
		Counter operator++(int);
		Counter& operator+=(double amount);

		void observe(double amount);
		void reset();

		double getvalue() const;

		//! @brief Increments the counter by the specified amount. The default increment is 1.
		//! Provides a convenient alias for the observe() method.
		void inc(double amount = 1) { this->observe(amount); }

	private:
		double m_value = 0;
	};
}
