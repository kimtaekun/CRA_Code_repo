
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestMatcher_Mocking/mocking.cpp"
using namespace testing;

class MockCalculator : public Cal {
public:
	MOCK_METHOD(int, getSum, (int a, int b), ());
};
class MockString : public std::string {
public:
	MOCK_METHOD(size_t, length, (), ());
};
class MockAssign : public IAssign {
public:
	MOCK_METHOD(bool, getPass, (int id, int pass), (override));
};

TEST(MockingTest, CalMock) {
	MockCalculator mock_cal;

	EXPECT_CALL(mock_cal, getSum(_, _)).WillRepeatedly(Return(-777));
	int ret1 = mock_cal.getSum(1, 2);
	int ret2 = mock_cal.getSum(1, 2);

	EXPECT_EQ(ret1, -777);
}

TEST(MockingTest, stringMock) {
	MockString mock_str;

	EXPECT_CALL(mock_str, length).WillRepeatedly(Return(777));
	int ret1 = mock_str.length();

	EXPECT_EQ(ret1, 777);
}

TEST(MockingTest, assignMock) {
	MockAssign mock_assign;

	EXPECT_CALL(mock_assign, getPass).WillRepeatedly(Return(true));
	Cal cal{ &mock_assign };

	EXPECT_EQ(cal.getSum(1,2,3,4), 3);
}
