#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Wheel {
public:
	int getPrice(vector<string> hide_text, string user_call_word) {
		strs = hide_text;
		int sum = 0;
		for (char check_char : user_call_word) {
			sum += get_lets_seconds_score(check_char);
			sum += get_lets_first_score(check_char);
			sum += get_find_char_score(get_find_char_cnt(check_char));
		}
		return sum;
	}
private:
	vector<string> strs;
	int ffirst[5] = { 0 };
	int chance[5] = { -1, -1, -1, -1, -1 };
	int conCnt = 0;

	const int lets_first_price = 1000;
	const int lets_seconds_price = 2000;
	const int find_char_price = 100;

	int get_lets_first_score(char check_char)
	{
		int score = 0;
		for (int y = 0; y < strs.size(); y++) {
			if (ffirst[y] != 0) {
				continue;
			}
			if (strs[y][0] == check_char) {
				//Let's First 점수인지 확인한다.
				score += lets_first_price;
				chance[y] = y;
				ffirst[y] = 1;
			}
		}
		return score;
	}
	int get_lets_seconds_score(char check_char)
	{
		int score = 0;
		//1. 2000 달러 찬스를 얻었는지 검사
		for (int y = 0; y < strs.size(); y++) {
			if (chance[y] == -1) {
				continue;
			}

			for (int x = 0; x < strs[chance[y]].size(); x++) {
				if (strs[chance[y]][x] == check_char) {
					//획득 성공시 2000달러를 얻는다.
					score += lets_seconds_price;
					break;
				}
			}
			chance[y] = -1;
		}
		return score;
	}
	int get_find_char_score(int find_char_cnt) {
		if (find_char_cnt > 0) conCnt++;
		return conCnt * find_char_cnt * find_char_price;
	}
	int get_find_char_cnt(char check_char)
	{
		int passCnt = 0;
		//2중 for 돌면서 정답 문자열을 하나씩 검사해서
		//퀴즈참가자가 던진 문자가 존재하는지 검사
		for (int y = 0; y < strs.size(); y++) {
			for (int x = 0; x < strs[y].size(); x++) {
				//만약 퀴즈참석자가 요청한 문자가, 
				//정답문자열과 동일하다면
				if (strs[y][x] != check_char) continue;

				ffirst[y] = 1;
				strs[y][x] = '_';
				passCnt++;
			}
		}
		if (passCnt == 0) not_find_char();
		return passCnt;
	}
	void not_find_char()
	{
		conCnt = 0;
		for (int i = 0; i < 5; i++) chance[i] = -1;
	}
};
