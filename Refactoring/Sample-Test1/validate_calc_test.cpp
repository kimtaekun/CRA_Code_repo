#include "pch.h"
#include "../Refactoring/validate_calc.cpp"

TEST(validate_calc, ��������InputTest) {
	Validate_Calc cal;
	EXPECT_EQ(cal.getResult("25+61=86"), "PASS");
}
TEST(validate_calc, ��������InputTest2) {
	Validate_Calc cal;
	EXPECT_EQ(cal.getResult("12345+12345=24690"), "PASS");
}
TEST(validate_calc, �����ڿ������ο���) {
	Validate_Calc cal;
	EXPECT_EQ(cal.getResult("5++5=10"), "ERROR");
}
TEST(validate_calc, Invalid�Ѱ������Fail) {
	Validate_Calc cal;
	EXPECT_EQ(cal.getResult("10000+1=10002"), "FAIL");
}