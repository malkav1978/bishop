#include "prometheus/gauge.hpp"

#include <cmath>

namespace prometheus
{
	//! @brief Pre-increment operator.
	Gauge& Gauge::operator++()
	{
		inc();
		return *this;
	}

	//! @brief Post-increment operator.
	Gauge Gauge::operator++(int)
	{
		inc();
		return *this;
	}

	//! @brief Addition assignment operator.
	Gauge& Gauge::operator+=(double amount)
	{
		inc(amount);
		return *this;
	}

	//! @brief Pre-decrement operator.
	Gauge& Gauge::operator--()
	{
		dec();
		return *this;
	}

	//! @brief Post-decrement operator.
	Gauge Gauge::operator--(int)
	{
		dec();
		return *this;
	}

	//! @brief Subtraction assignment operator.
	Gauge& Gauge::operator-=(double amount)
	{
		dec(amount);
		return *this;
	}

	/** 
	 * @brief Increments the gauge by the given amount. The default increment is 1.
	 * @param amount The amount to increment the gauge by.
	 */
	void Gauge::inc(double amount)
	{
		m_value += std::abs(amount);
	}

	/** 
	 * @brief Decrements the gauge by the given amount. The default increment is 1.
	 * @param amount The amount to decrement the gauge by.
	 */
	void Gauge::dec(double amount)
	{
		m_value -= std::abs(amount);
	}

	/** 
	 * @brief Sets the gauge to the given value.
	 * @param value The value to set the gauge to.
	 */
	void Gauge::set(double value)
	{
		m_value = value;
	}

	//! @brief Resets the gauge to 0.
	void Gauge::reset()
	{
		m_value = 0;
	}

	//! @brief Gets the current value of the gauge.
	double Gauge::getvalue() const
	{
		return m_value;
	}
}
