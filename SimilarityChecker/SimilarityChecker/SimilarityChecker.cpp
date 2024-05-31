#include <string>
#include <stdexcept>
#include <algorithm> // std::all_of
#include <cctype>    // std::isupper

class SimilarityChecker {
public:
	SimilarityChecker(std::string _target) :target{ _target } {};

	int get_length_score(std::string matched_str) {
		if (false == std::all_of(matched_str.begin(), matched_str.end(), [](unsigned char c) {return std::isupper(c); })) {
			throw std::invalid_argument("Must be use Upper string");
		}
		if (matched_str.length() == target.length()) return 60;
		return 0;
	}

private:
	std::string target;
};
