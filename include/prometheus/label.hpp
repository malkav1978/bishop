#pragma once

#include <map>
#include <string>
#include <utility>

namespace prometheus
{
	/// @brief Multiple labels and their value.
	// using Labels = std::map<std::string, std::string>;

	class Label : protected std::pair<std::string, std::string>
	{
	public:
		using key_type = std::string;
		using value_type = std::string;

		Label(const std::string& name, const std::string& value);

		const std::string& name() const;
		const std::string& value() const;
	};
}
