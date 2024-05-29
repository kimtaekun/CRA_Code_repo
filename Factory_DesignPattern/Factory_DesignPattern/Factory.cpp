#include <iostream>
#include <string>

class Doll {
public:
	virtual void push() = 0;
	Doll(std::string lan) : language(lan) {

	}
protected:
	std::string language;
};

class RedDoll : public Doll {
public:
	// Doll¿ª(∏¶) ≈Î«ÿ ªÛº”µ 
	void push() override
	{
		if (language == "korea") {
			std::cout << "ª°∞≠ æ»≥Á" << std::endl;
		}
		else if (language == "swiss") {
			std::cout << "hello red" << std::endl;
		}
	}
	RedDoll(std::string lan) : Doll(lan) {

	}
};
class BlueDoll : public Doll {
public:
	// Doll¿ª(∏¶) ≈Î«ÿ ªÛº”µ 
	void push() override
	{
		if (language == "korea") {
			std::cout << "∆ƒ∂˚ æ»≥Á" << std::endl;
		}
		else if (language == "swiss") {
			std::cout << "hello blue" << std::endl;
		}
	}
	BlueDoll(std::string lan) : Doll(lan) {

	}
};


class DollFacotry {
public:
	virtual Doll* makeDoll(std::string doll_type) = 0;
};

class KoreanDoolFacotry : public DollFacotry {
public:
	// DollFacotry¿ª(∏¶) ≈Î«ÿ ªÛº”µ 
	Doll* makeDoll(std::string doll_type) override
	{
		if (doll_type == "RED") return new RedDoll("korea");
		if (doll_type == "BLUE") return new BlueDoll("korea");
		return nullptr;
	}
};
class SwissDoolFacotry : public DollFacotry {
public:
	// DollFacotry¿ª(∏¶) ≈Î«ÿ ªÛº”µ 
	Doll* makeDoll(std::string doll_type) override
	{
		if (doll_type == "RED") return new RedDoll("swiss");
		if (doll_type == "BLUE") return new BlueDoll("swiss");
		return nullptr;
	}
};
//
//int main() {
//	SwissDoolFacotry fac;
//	auto doll = fac.makeDoll("BLUE");
//
//	doll->push();
//}