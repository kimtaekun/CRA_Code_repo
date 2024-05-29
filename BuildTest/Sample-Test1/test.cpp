#include "pch.h"
#include "../BuildTest/cal.cpp"

TEST(getSumTest, three_puls_four_Test_Positive) {
	int ret = getSum(3, 4);
	EXPECT_EQ(7, ret) << "getSum Method Result is not 3+4";
}

TEST(getSumTest, three_puls_four_Test_Negative) {
	int ret = getSum(3, 4);
	EXPECT_EQ(0, ret) << "getSum Method Result is not 3+4";
}
