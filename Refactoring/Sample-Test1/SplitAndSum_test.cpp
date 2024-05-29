#include "pch.h"
#include "../Refactoring/SplitAndSum.cpp"

TEST(SplitAndSum, SumThree) {
	int actual = splitAndSum("10-20-30");
	EXPECT_EQ(actual, 60);
}
TEST(SplitAndSum, SumFour) {
	int actual = splitAndSum("300-10-20-30");
	EXPECT_EQ(actual, 360);
}
TEST(SplitAndSum, SumOne) {
	int actual = splitAndSum("10");
	EXPECT_EQ(actual, 10);
}