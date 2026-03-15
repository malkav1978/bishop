#pragma once

namespace prometheus
{
	/**
	 * @brief Base class for all metric types.
	 */
	class Type
	{
	public:
		virtual void observe(double amount) = 0;
	};
}
