#include "prometheus/histogram.hpp"

#include <iostream>

int main()
{
	prometheus::Histogram histogram({ 0.1, 0.2, 0.3, 0.4, 0.5 });

	histogram.observe(0.05);
	histogram.observe(0.15);
	histogram.observe(0.24);
	histogram.observe(0.25);
	histogram.observe(0.35);
	histogram.observe(0.45);
	histogram.observe(1.0);

	for(const auto& [ bucket, count ] : histogram.getvalues())
	{
		std::cout << "Bucket: " << bucket << ", Count: " << count << std::endl;
	}
}
