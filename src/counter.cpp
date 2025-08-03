#include "prometheus/metric.hpp"
#include "prometheus/counter.hpp"

#include <stdexcept>

namespace prometheus
{
	Counter::Counter(const std::string& name, const std::string& description)
		: Metric(name, description)
	{
	}

	void Counter::inc(double amount)
	{
		if(amount < 0)
		{
			throw std::invalid_argument("negative increment is not allowed");
		}

		this->m_value += amount;
	}

	void Counter::reset()
	{
		this->m_value = 0;
	}

	double Counter::value() const
	{
		return this->m_value;
	}
}
