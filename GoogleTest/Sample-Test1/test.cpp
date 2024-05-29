#include "pch.h"
#include "../GoogleTest/calc.cpp"

TEST(getAbsoluteSum_Test, Positive_Value_Test) {
	std::vector<int> Test_num_list = { 1, 2, 3, 4, 5, 6, 9999 };

	auto actual = getAbsoluteSum(Test_num_list);

	EXPECT_EQ(Test_num_list, actual);
}

TEST(getAbsoluteSum_Test, Negative_Value_Test) {
	std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 9999 };
	std::vector<int> Test_num_list = { -1, -2, -3, -4, -5, -6, -9999 };

	auto actual = getAbsoluteSum(Test_num_list);

	EXPECT_EQ(expected, actual);
}

TEST(getAbsoluteSum_Test, Zero_Value_Test) {
	std::vector<int> expected = { 0, };
	std::vector<int> Test_num_list = { 0, };

	auto actual = getAbsoluteSum(Test_num_list);

	EXPECT_EQ(expected, actual);
}

TEST(getAbsoluteSum_Test, Mix_Value_Test) {
	std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 9999, 0  };
	std::vector<int> Test_num_list = { -1, -2, 3, -4, -5, -6, 9999, 0 };

	auto actual = getAbsoluteSum(Test_num_list);

	EXPECT_EQ(expected, actual);
}
