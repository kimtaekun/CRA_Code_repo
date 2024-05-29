#include <string>
#include <unordered_map>
using std::string;

class Tennis {
public:
	const string tennis_score(int p1Score, int p2Score) {
		if (p1Score == p2Score)
		{
			return get_same_score_name(p1Score);
		}

		if (p1Score >= 4 || p2Score >= 4)
		{
			return get_winner_name(p1Score, p2Score);
		}

		return score_name[p1Score] + "-" + score_name[p2Score];
	}

private:
	std::unordered_map<int, string> score_name {
		{0, "Love"}, { 1, "Fifteen" }, {2, "Thirty"}, {3, "Forty"},
	};

	const string get_same_score_name(int score) {
		if (score < 3) {
			return score_name[score] + "-All";
		}

		return "Deuce";
	}

	const string get_winner_name(int p1_score, int p2_score) {
		int minusResult = p1_score - p2_score;
		string winner_name = std::abs(minusResult) == 1 ? "Advantage " : "Win for ";
		winner_name += minusResult > 0 ? "player1" : "player2";
		return winner_name;
	}
};
