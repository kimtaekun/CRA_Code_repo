#include "game_better.h"

using namespace std;

Player::Player(string _name)
	: name(_name), places(0), purses(0), inPenaltyBox(false) {
}

Question::Question()
{
	for (int i = 0; i < 50; i++) {
		questions_list["Pop"].push_back(createQuestion("Pop", i));
		questions_list["Science"].push_back(createQuestion("Science", i));
		questions_list["Sports"].push_back(createQuestion("Sports", i));
		questions_list["Rock"].push_back(createQuestion("Rock", i));
	}
}

string Question::createQuestion(string type, int index)
{
	return type + " Question " + to_string(index);
}

void Question::askQuestion(string category)
{
	cout << questions_list[category].front() << endl;
	questions_list[category].pop_front();
}

Game_Better::Game_Better()
{
}

bool Game_Better::isPlayable()
{
	return (howManyPlayers() >= 2);
}

bool Game_Better::add(string playerName)
{
	players.push_back(Player(playerName));
	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	currentPlayer = players.begin();
	return true;
}

int Game_Better::howManyPlayers()
{
	return (int)players.size();
}

void Game_Better::rolling(int roll)
{
	cout << currentPlayer->getName() << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if (currentPlayer->isinPenaltyBox()) {
		if (roll % 2 != 0) {
			outPenaltyBox(roll);
			return;
		}
		stayPenaltyBox();
		return;
	}
	movePlaces(roll);
}

void Game_Better::movePlaces(int roll)
{
	currentPlayer->movePlace(roll);
	cout << currentPlayer->getName() << "'s new location is " << currentPlayer->getCurPlace() << endl;
	cout << "The category is " << currentCategory() << endl;
	Qcard.askQuestion(currentCategory());
}

void Game_Better::stayPenaltyBox()
{
	cout << currentPlayer->getName() << " is not getting out of the penalty box" << endl;
}

void Game_Better::outPenaltyBox(int roll)
{
	cout << currentPlayer->getName() << " is getting out of the penalty box" << endl;
	currentPlayer->exitPenaltyBox();
	movePlaces(roll);
}


string Game_Better::currentCategory()
{
	switch (currentPlayer->getCurPlace() % 4)
	{
	case 0:
		return "Pop";
	case 1:
		return "Science";
	case 2:
		return "Sports";
	default:
		return "Rock";
	}
	return string();
}

void Game_Better::next_player()
{
	++currentPlayer;
	if (currentPlayer == players.end()) {
		currentPlayer = players.begin();
	}
}

bool Game_Better::wasCorrectlyAnswered()
{
	if (is_stay_in_penalty_box()) {
		next_player();
		return true;
	}

	return answer_correct();
}
bool Game_Better::wrongAnswer()
{
	if (is_stay_in_penalty_box()) {
		next_player();
		return true;
	}

	goto_penalty_box();
	return true;
}

bool Game_Better::answer_correct()
{
	currentPlayer->exitPenaltyBox();
	cout << "Answer was correct!!!!" << endl;

	currentPlayer->addCoin();
	cout << currentPlayer->getName() << " now has "
		<< currentPlayer->getCoinCount() << " Gold Coins." << endl;

	bool winner = currentPlayer->didPlayerWin();
	next_player();

	return winner;
}

void Game_Better::goto_penalty_box()
{
	cout << "Question was incorrectly answered" << endl;
	cout << currentPlayer->getName() + " was sent to the penalty box" << endl;
	currentPlayer->gotoPenaltyBox();
	next_player();
}

bool Game_Better::is_stay_in_penalty_box()
{
	return currentPlayer->isinPenaltyBox();
}
