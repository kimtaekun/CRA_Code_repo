#include "pch.h"
#include "../WheelOfFortune/wheel.cpp"

TEST(WheelTest, Input1Test) {
	vector<string> strs{ "BUILDLEV","EATREALROBOT" };
	string userdata = "ERABCDFGHIJKLMNOPQSTUVWXYZ";

	Wheel app;
	int actual = app.getPrice(strs, userdata);
	int expected = 6500;

	EXPECT_EQ(actual, expected);
}

TEST(WheelTest, Input2Test) {
	vector<string> strs{ "ABS","ABS","AAAAAKBA" };
	string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";

	Wheel app;
	int actual = app.getPrice(strs, userdata);
	int expected = 9500;

	EXPECT_EQ(actual, expected);
}

TEST(WheelTest, Input3Test) {
	vector<string> strs{ "DHRBCVNS","QQWECVN","AUIJHVDDDDD","LGHVFRH","ETYGV" };
	string userdata = "ERABCDFGHIJKLMNOPQSTUVWXYZ";

	Wheel app;
	int actual = app.getPrice(strs, userdata);
	int expected = 20500;

	EXPECT_EQ(actual, expected);
}