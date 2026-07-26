#pragma once

#include <vector>

namespace prometheus
{
	/**
	 * @brief Provides a class to handle Histograms aggregatable distributions of events.
	 * @see https://prometheus.io/docs/instrumenting/writing_clientlibs/#histogram
	 */
	class Histogram
	{
	public:
		/// @brief Represents a bucket in the histogram.
		using Buckets = std::vector<std::pair<double, std::size_t>>;

		/// @brief Constructs a Histogram with the given bucket values.
		explicit Histogram(const std::vector<double>& buckets);

		/// @brief Observes a value, updating the histogram's count and sum.
		void observe(double value);

		/// @brief Returns the number of observations.
		std::size_t count() const { return m_count; }

		/// @brief Returns the sum of all observations.
		double sum() const { return m_sum; }

		/// @brief Returns the bucket values.
		const Buckets& getvalues() const { return m_buckets; }

	private:
		double m_sum = 0;

		std::size_t m_count = 0;

		Buckets m_buckets;
	};
}
