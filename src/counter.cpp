#include "prometheus/counter.hpp"

#include <stdexcept>

namespace prometheus
{
	//! @brief Pre-increment operator.
	Counter& Counter::operator++()
	{
		this->inc();
		return *this;
	}

	//! @brief Post-increment operator.
	Counter Counter::operator++(int)
	{
		this->inc();
		return *this;
	}

	//! @brief Compound assignment operator.
	Counter& Counter::operator+=(double amount)
	{
		this->inc(amount);
		return *this;
	}

	/**
	 * @brief Increments the counter by the specified amount (default is 1).
	 *
	 * @param amount The amount to increment the counter by. Must be non-negative.
	 * @throws std::invalid_argument if the amount is negative.
	 */
	void Counter::inc(double amount)
	{
		if(amount >= 0)
		{
			this->m_value += amount;
		}
		else
		{
			throw std::invalid_argument("negative increment is not allowed");
		}
	}

	//! @brief Resets the counter to zero.
	void Counter::reset()
	{
		this->m_value = 0;
	}

	//! @brief Returns the current value of the counter.
	double Counter::getvalue() const
	{
		return this->m_value;
	}
}
