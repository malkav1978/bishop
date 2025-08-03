#include "prometheus/metric.hpp"

namespace prometheus
{
	
	Metric::Metric(const std::string& name, const std::string& description)
		: m_name{name}, m_description{description}
	{
	}

	const std::string& Metric::name() const
	{
		return this->m_name;
	}

	const std::string& Metric::description() const
	{
		return this->m_description;
	}

}
