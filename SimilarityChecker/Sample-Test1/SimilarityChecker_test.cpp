#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixtrue : public testing::Test {
public:
	SimilarityChecker checker{ "ABC" };
};

TEST_F(SimilarityCheckerFixtrue, ExceptionOccurWhenInvalidChar) {
	EXPECT_THROW(checker.get_length_score("abc"), std::invalid_argument);
}
TEST_F(SimilarityCheckerFixtrue, Get60ScoreWhenMatchedLength) {
	EXPECT_EQ(checker.get_length_score("ABC"), 60);
}