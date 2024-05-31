#include <vector>
#include <stdexcept>
class matcher_vector {
public:
	matcher_vector(std::vector<int> origin) :
		vec_target{ origin } {
		for (int val : vec_target) {
			if (val == 4 || val >= 10) {
				throw std::range_error("must be use 10 under and not 4");
			}
		}
	}
	std::vector<int> return_vector() {
		for (int& val : vec_target) {
			val++;
			if (val == 4) val = 5;
			if (val >= 10) val = 0;
		}
		return vec_target;
	}
private:
	std::vector<int> vec_target;
};