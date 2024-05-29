#include <string>
#define interface struct

interface Walkable {
	virtual void walk() = 0;
	virtual void run() = 0;
};
interface Flyable {
	virtual void fly() = 0;
};

class Superman : public Walkable, Flyable {
	// Move을(를) 통해 상속됨
	void walk() override
	{
	}
	void run() override
	{
	}
	void fly() override
	{
	}
};
class Bateman : public Walkable {
	// Move을(를) 통해 상속됨
	void walk() override
	{
	}
	void run() override
	{
	}
};