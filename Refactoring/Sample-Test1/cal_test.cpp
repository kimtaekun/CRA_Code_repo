#include "pch.h"
#include "../Refactoring/cal.cpp"

class GlobalEnv : public testing::Environment {
public:
	// Override this to define how to set up the environment.
	void SetUp() {
		std::cout << "Test Ready!!\n";
	}

	// Override this to define how to tear down the environment.
	void TearDown() {
		std::cout << "Clean Up!!\n";
	}
};

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	testing::AddGlobalTestEnvironment(new GlobalEnv);
	return RUN_ALL_TESTS();
}

class EvenTestFixture : public testing::Test {
public:
	Cal cal; // SUT
	std::vector<int> target;
	std::vector<std::string> expeted;

	void EvenCheck() {
		EXPECT_EQ(cal.getEvenValue(target), expeted);
	}
protected:
	// Sets up the test fixture.
	virtual void SetUp() {

	}
	// Tears down the test fixture.
	virtual void TearDown() {

	}
};

TEST_F(EvenTestFixture, noneVector) {
	EvenCheck();
}

TEST_F(EvenTestFixture, onlyEven) {
	target = std::vector<int>{ 2,4,6,8,10 };
	EvenCheck();
}

TEST_F(EvenTestFixture, onlyOdd) {
	target = std::vector<int>{ 1,3,5,7,9 };
	EvenCheck();
}

TEST_F(EvenTestFixture, Mix) {
	target = std::vector<int>{ 1,2,3,4,5,6 };
	expeted = std::vector<std::string>{ "X", "O","X", "O" ,"X", "O" };
	EvenCheck();
}
