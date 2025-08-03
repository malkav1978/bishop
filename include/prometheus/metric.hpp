#pragma once

#include <string>

namespace prometheus
{
	class Metric
	{
	public:
		Metric(const std::string& name, const std::string& description);

		const std::string& name() const;
		const std::string& description() const;

	private:
		const std::string m_name;
		const std::string m_description;
	};
}
