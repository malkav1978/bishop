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
		void inc(double amount = 1);
		void reset();

		double getvalue() const;

	private:
		double m_value = 0;
	};
}
