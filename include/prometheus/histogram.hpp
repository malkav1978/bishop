#pragma once

#include <vector>

namespace prometheus
{
	class Type;

	/**
	 * @brief Provides a histogram to observe and bucket values.
	 * @see https://prometheus.io/docs/instrumenting/writing_clientlibs/#histogram
	 */
	class Histogram : public Type
	{
	public:
		using Buckets = std::vector<std::pair<double, std::size_t>>;

		Histogram() = default;
		Histogram(const std::vector<double>& buckets);

		void observe(double value) override;

		std::size_t getCount() const
		{
			return m_count;
		}

		double getSum() const
		{
			return m_sum;
		}

		const Buckets& getvalues() const
		{
			return m_buckets;
		}

	private:
		double m_sum = 0;

		std::size_t m_count = 0;

		Buckets m_buckets;
	};
}
