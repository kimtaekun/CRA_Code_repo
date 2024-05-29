#include <iostream>
#include <string>

class Jewelry {
public:
	virtual void showinfo() = 0;
};

class Gold : public Jewelry {
public:
	// Jewelry을(를) 통해 상속됨
	void showinfo() override
	{
		std::cout << "name : Gold" << "\t" << "price : 10$" << std::endl;
	}
};
class Ruby : public Jewelry {
public:
	// Jewelry을(를) 통해 상속됨
	void showinfo() override
	{
		std::cout << "name : Ruby" << "\t" << "price : 5$" << std::endl;
	}
};
class Diamond : public Jewelry {
public:
	// Jewelry을(를) 통해 상속됨
	void showinfo() override
	{
		std::cout << "name : Diamond" << "\t" << "price : 15$" << std::endl;
	}
};

class JewelryFactory {
public:
	static JewelryFactory& getInstance() {
		static JewelryFactory instance;
		return instance;
	}

	Jewelry* makeJewelry(std::string type) {
		if (type == "gold") return new Gold();
		if (type == "ruby") return new Ruby();
		if (type == "diamond") return new Diamond();
		return nullptr;
	}
private:
	JewelryFactory() = default;
	JewelryFactory(const JewelryFactory& other) = delete;
	JewelryFactory& operator=(const JewelryFactory& other) = delete;
};

int main() {
	JewelryFactory& fac = JewelryFactory::getInstance();
	fac.makeJewelry("gold")->showinfo();
	fac.makeJewelry("ruby")->showinfo();
	fac.makeJewelry("diamond")->showinfo();
}