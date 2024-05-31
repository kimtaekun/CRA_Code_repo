#include <string>
#include <stdexcept>
#include <algorithm> // std::all_of
#include <cctype>    // std::isupper
#include <unordered_map>    // std::isupper

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

	int get_alpha_score(std::string matched_str) {
		throw_exception_not_all_upper_char(matched_str);		
		make_matched_map(matched_str);
		int total_cnt = matched_map.size();
		int match_cnt = get_matched_count();
		return (double)match_cnt / total_cnt * 40;
	}
private:
	std::string target;
	std::unordered_map<char, bool> matched_map;

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

	void make_matched_map(std::string matched_str)
	{
		matched_map.clear();
		for (char ch : matched_str) {
			matched_map_insert(ch);
			for (char tar_ch : target) {
				matched_map_insert(tar_ch);
				matched_map_countup(ch, tar_ch);
			}
		}
	}
	void matched_map_insert(char ch)
	{
		if (matched_map.find(ch) == matched_map.end()) {
			matched_map[ch] = false;
		}
	}
	void matched_map_countup(char ch, char tar_ch)
	{
		if (ch != tar_ch) { return; };
		matched_map[ch]++;
	}
	int get_matched_count()
	{
		int match_cnt = 0;
		for (auto match_ch : matched_map) {
			if (match_ch.second == false) continue;
			match_cnt++;
		}
		return match_cnt;
	}
};
