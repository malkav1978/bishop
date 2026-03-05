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

		void inc(double amount = 1);
		void reset();

		double getvalue() const;

	private:
		double m_value = 0;
	};
}
