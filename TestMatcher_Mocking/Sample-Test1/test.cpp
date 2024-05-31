
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestMatcher_Mocking/matcher_vector.cpp"
using namespace testing;

TEST(Expect_That_Test, ListMatch) {
	matcher_vector vec{ {1,2,2,5} };
	std::vector<int> expected{ 2,3,3,6 };
	EXPECT_THAT(vec.return_vector(), ContainerEq(expected));
}
TEST(Expect_That_Test, ListMatch_over10) {
	matcher_vector vec{ {1,2,8,9} };
	std::vector<int> expected{ 2,3,9,0 };
	EXPECT_THAT(vec.return_vector(), ContainerEq(expected));
}
TEST(Expect_That_Test, ListMatch_jump4) {
	matcher_vector vec{ {1,2,3} };
	std::vector<int> expected{ 2,3,5 };
	EXPECT_THAT(vec.return_vector(), ContainerEq(expected));
}
TEST(Expect_That_Test, Exception_Input4) {
	try {
		matcher_vector vec{ {1,2,3,4} };
		FAIL();
	}
	catch (std::range_error& e) {}
}
TEST(Expect_That_Test, Exception_Input_over10) {
	try {
		matcher_vector vec{ {10,2,3,5} };
		FAIL();
	}
	catch (std::range_error& e) {}
}
