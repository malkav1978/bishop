#pragma once

namespace prometheus
{
	class Metric;
	class Counter : public Metric
	{
	public:
		Counter(const std::string& name, const std::string& description);

		void inc(double amount = 1);
		void reset();

		double value() const;

	private:
		double m_value = 0;
	};
}
