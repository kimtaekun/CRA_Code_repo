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
		if (check_match_length(matched_str)) return 60;
		if (check_over_twice(matched_str.length())) return 0;
		return get_parial_score(matched_str.length());
	}

private:
	std::string target;
	void throw_exception_not_all_upper_char(std::string str) {
		if (false == std::all_of(str.begin(), str.end(), [](unsigned char c) {return std::isupper(c); })) {
			throw std::invalid_argument("Must be use Upper string");
		}
	}
	bool check_match_length(std::string& matched_str)
	{
		return matched_str.length() == target.length();
	}

	bool check_over_twice(size_t matched_length)
	{
		int diff_length = std::abs((int)(matched_length - target.length()));
		int min_length = matched_length > target.length() ? target.length() : matched_length;
		return diff_length >= min_length;
	}

	int get_parial_score(size_t matched_length) {
		int diff_length = std::abs((int)(matched_length - target.length()));
		int min_length = matched_length > target.length() ? target.length() : matched_length;
		return (1 - (double)diff_length / min_length) * 60;
	}
};
