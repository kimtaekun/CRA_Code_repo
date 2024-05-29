#include <iostream>

class GameMachine {
private:
	unsigned int totalCoin;

public:
	GameMachine() : totalCoin{ 0 } {

	}
	void inputCoin(unsigned int coin_num) {
		if (coin_num > 5) {
			std::cout << "�ԷµǴ� Coin�� 5���� ���� �� �����ϴ�." << std::endl;
			return;
		}
		if (totalCoin + coin_num > 10) {
			std::cout << "�� Coin�� 10���� ���� �� �����ϴ�." << std::endl;
			return;
		}
		totalCoin += coin_num;
	}
	void PlayGame() {
		if (totalCoin == 0) {
			std::cout << "���Ե� Coin�� �����մϴ�." << std::endl;
			return;
		}
		totalCoin--;
	}
	unsigned int getTotalCoin() {
		return totalCoin;
	}	
};
//
//int main() {
//	GameMachine gm;
//
//	gm.inputCoin(5);
//	gm.PlayGame();
//	gm.PlayGame();
//	gm.PlayGame();
//	gm.PlayGame();
//	gm.PlayGame();
//	gm.PlayGame();
//	gm.PlayGame();
//
//	std::cout << "���� Coin ���� : " << gm.getTotalCoin() << std::endl;
//	return 0 ;
//}
//
