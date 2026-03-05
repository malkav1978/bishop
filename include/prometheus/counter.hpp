#pragma once

namespace prometheus
{
	class Counter
	{
	public:
		void inc(double amount = 1);
		void reset();

		double value() const;

	private:
		double m_value = 0;
	};
}
