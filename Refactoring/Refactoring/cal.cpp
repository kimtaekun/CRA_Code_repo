#include <vector>
#include <string>

class Cal {
public:
	int getSum(int a, int b) {
		return a + b;
	}

	std::vector<std::string> getEvenValue(std::vector<int>& target) {
		std::vector<std::string> ret;
		int exist_even = 0, exist_odd = 0;
		for (int value : target) {
			if (value % 2 == 0) {
				exist_even = 1;
				ret.push_back("O");
			}
			else {
				exist_odd = 1;
				ret.push_back("X");
			}
		}

		if (exist_odd + exist_even == 1) {
			return std::vector<std::string>();
		}
		return ret;
	}
};