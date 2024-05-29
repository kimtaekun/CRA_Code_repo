#include <iostream>

class Zergling {
private:
	int hp;
	int mana;

public:
	Zergling() : hp{ 80 }, mana{ 200 } {
		
	}
	void attack() {
		hp++;
		mana -= 10;
	}
	void move() {
		hp -= 10;
		mana += 5;
	}
	void status() {
		std::cout << hp << " " << mana << std::endl;
	}
};
//
//int main() {
//	Zergling z1;
//	Zergling z2;
//
//	z1.status();
//	z2.status();
//}
