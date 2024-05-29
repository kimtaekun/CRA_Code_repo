#include <string>
#define interface struct
using namespace std;

interface Formality {
	virtual std::string formal() {
		return "Hello.";
	};
};

class Formal : public Formality {
public:
	// Formality을(를) 통해 상속됨
	std::string formal() override
	{
		return "Good evening, sir.";
	}
};

class Casual : public Formality {
public:
	// Formality을(를) 통해 상속됨
	std::string formal() override
	{
		return "Sup bro?";
	}
};
class Intimate : public Formality {
public:
	// Formality을(를) 통해 상속됨
	std::string formal() override
	{
		return "Hello Darling!";
	}
};


class Greeter {
public:
	string Greet() {
		return formality->formal();
	}

	void SetFormality(Formality* formality) {
		this->formality = formality;
	}

private:
	Formality* formality;
};
