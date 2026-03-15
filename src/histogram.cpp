#include "prometheus/type.hpp"
#include "prometheus/histogram.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace prometheus
{
	Histogram::Histogram(const std::vector<double>& buckets)
	{
		m_buckets.reserve(buckets.size() + 1);
		for (const auto& le : buckets)
		{
			m_buckets.emplace_back(le, 0);
		}

		m_buckets.emplace_back(std::numeric_limits<double>::infinity(), 0);
		std::sort(m_buckets.begin(), m_buckets.end());
	}

	void Histogram::observe(double value)
	{
		m_sum += value;
		++m_count;

		auto it = std::lower_bound
		(
			m_buckets.begin(),
			m_buckets.end(), value,
			[](const auto& bucket, double val)
			{
				return bucket.first < val;
			}
		);

		while (it != m_buckets.end())
		{
			++it->second;
			++it;
		}
	}
}
