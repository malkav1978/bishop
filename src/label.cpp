#include "prometheus/label.hpp"

#include <regex>
#include <stdexcept>

static const std::string& validate(const std::string& name)
{
	using namespace std::literals;

	if(name.starts_with("__"s))
	{
		throw std::invalid_argument("label name reserved for internal Prometheus use");
	}

	static const std::regex label_name("[a-zA-Z_][a-zA-Z0-9_]*");

	std::smatch match;

	if(std::regex_match(name, match, label_name))
	{
		return name;
	}
	else
	{
		throw std::invalid_argument("invalid label name ");
	}
}

namespace prometheus
{
	Label::Label(const std::string& name, const std::string& value)
		: std::pair<std::string, std::string>{validate(name), value}
	{
	}

	const std::string& Label::name() const
	{
		return this->first;
	}

	const std::string& Label::value() const
	{
		return this->second;
	}
}
