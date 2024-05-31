#include <string>
#include <stdexcept>
#include <algorithm> // std::all_of
#include <cctype>    // std::isupper

class SimilarityChecker {
public:
	SimilarityChecker(std::string _target) {
		throw_exception_not_all_upper_char(_target);
		target = _target;
	};

	int get_length_score(std::string matched_str) {
		throw_exception_not_all_upper_char(matched_str);
		if (matched_str.length() == target.length()) return 60;
		return 0;
	}

private:
	std::string target;
	void throw_exception_not_all_upper_char(std::string str) {
		if (false == std::all_of(str.begin(), str.end(), [](unsigned char c) {return std::isupper(c); })) {
			throw std::invalid_argument("Must be use Upper string");
		}
	}
};
