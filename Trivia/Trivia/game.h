#ifndef GAME_H_
#define GAME_H_

#include "IGame.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::string;
using std::list;
using std::vector;

class Game : public IGame {
public:
	Game();

	string createRockQuestion(int index);
	bool isPlayable();
	int howManyPlayers();

	bool add(string playerName) override;
	void rolling(int roll) override;
	bool wasCorrectlyAnswered() override;
	bool wrongAnswer() override;


private:
	vector<string> players;

	int places[6];
	int purses[6];

	bool inPenaltyBox[6];

	list<string> popQuestions;
	list<string> scienceQuestions;
	list<string> sportsQuestions;
	list<string> rockQuestions;

	int currentPlayer;
	bool isGettingOutOfPenaltyBox;

	void askQuestion();
	string currentCategory();
	bool didPlayerWin();
};

#endif /* GAME_H_ */