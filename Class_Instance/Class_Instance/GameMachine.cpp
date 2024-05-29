#include <iostream>

class GameMachine {
private:
	unsigned int totalCoin;

public:
	GameMachine() : totalCoin{ 0 } {

	}
	void inputCoin(unsigned int coin_num) {
		if (coin_num > 5) {
			std::cout << "입력되는 Coin은 5개를 넘을 수 없습니다." << std::endl;
			return;
		}
		if (totalCoin + coin_num > 10) {
			std::cout << "총 Coin은 10개를 넘을 수 없습니다." << std::endl;
			return;
		}
		totalCoin += coin_num;
	}
	void PlayGame() {
		if (totalCoin == 0) {
			std::cout << "투입된 Coin이 부족합니다." << std::endl;
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
//	std::cout << "남은 Coin 갯수 : " << gm.getTotalCoin() << std::endl;
//	return 0 ;
//}
//
