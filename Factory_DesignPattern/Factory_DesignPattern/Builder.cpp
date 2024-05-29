#include <iostream>

class Chaining {
public:
	Chaining& a() {
		std::cout << "A" << " ";
		return *this;
	}
	Chaining& b() {
		std::cout << "B" << " ";
		return *this;
	}
	Chaining& c() {
		std::cout << "C" << " ";
		return *this;
	}
};
//
//int main() {
//	Chaining& something = (*new Chaining).a().b().c();
//	return 0;
//}