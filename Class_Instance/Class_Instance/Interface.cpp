#include <iostream>
#define interface struct

interface Socket
{
	virtual void plugin() = 0;
	virtual void unplug() = 0;
};

class DanSang : public Socket {
public:
	// Socket을(를) 통해 상속됨
	void plugin() override
	{
		zizic(); zizic(); zizic();
	}
	void unplug() override
	{
		zizic(); zizic();
	}

private:
	void zizic() {
		std::cout << "zizic.." << std::endl;
	}
};

class SamSang : public Socket {
public:
	// Socket을(를) 통해 상속됨
	void plugin() override
	{
		sam();
	}
	void unplug() override
	{
		sam(); sam();
	}

private:
	void sam() {
		std::cout << "330v.." << std::endl;
	}
};
//
//int main() {
//	Socket* sock = new DanSang();
//
//	sock->plugin();
//	sock->unplug();
//}