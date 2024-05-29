#ifndef GAME_BETTER_H_
#define GAME_BETTER_H_

#include "IGame.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::list;
using std::vector;
using std::unordered_map;

class Player {
public:
	Player(string _name);

	std::string getName() {
		return name;
	}

	bool isinPenaltyBox() {
		return inPenaltyBox;
	}
	void gotoPenaltyBox() {
		inPenaltyBox = true;
	}
	void exitPenaltyBox() {
		inPenaltyBox = false;
	}
	void addCoin() {
		purses++;
	}
	int getCoinCount() {
		return purses;
	}
	void movePlace(int roll) {
		places += roll;
		places %= 12;
	}
	int getCurPlace() {
		return places;
	}
	bool didPlayerWin()
	{
		return !(purses == 6);
	}

private:
	string name;
	int places;
	int purses;

	bool inPenaltyBox;
};
class Question {
public:
	Question();

	void askQuestion(string category);
private:
	string createQuestion(string type, int index);
	unordered_map<string, list<string>> questions_list;
};

class Game_Better : public IGame {
public:
	Game_Better();
	bool isPlayable();
	int howManyPlayers();

	bool add(string playerName) override;
	void rolling(int roll) override;
	bool wasCorrectlyAnswered() override;
	bool wrongAnswer() override;


private:
	Question Qcard;
	vector<Player> players;

	std::vector<Player>::iterator currentPlayer;

	void stayPenaltyBox();
	void outPenaltyBox(int roll);
	void movePlaces(int roll);
	bool answer_correct();
	void goto_penalty_box();
	void next_player();

	bool is_stay_in_penalty_box();
	string currentCategory();
};
#endif /* GAME_H_ */