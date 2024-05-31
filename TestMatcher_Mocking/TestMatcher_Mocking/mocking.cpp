#define interface struct

interface IAssign {
	virtual bool getPass(int id, int pass) = 0;
};

class Assgin : public IAssign {
public:
	bool getPass(int id, int pass) {
		return true;
	}
};

class Cal {
public:
	Cal() = default;
	Cal(IAssign* i) : assign{ i } {}

	int getSum(int a, int b, int id, int pass) {
		if (assign->getPass(id, pass) == false) return 0;
		return a + b;
	}

private:
	IAssign* assign;
};