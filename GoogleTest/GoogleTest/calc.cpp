#include <vector>

std::vector<int> getAbsoluteSum(std::vector<int> num_list) {
	std::vector<int> ret;
	for (auto num : num_list) {
		ret.push_back(std::abs(num));
	}

	return ret;
}
