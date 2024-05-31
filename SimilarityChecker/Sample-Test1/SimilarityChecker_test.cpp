#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixtrue : public testing::Test {
public:
	SimilarityChecker checker{ "ABCED" };
};

TEST(SimilarityCheckerTest, ExceptionOccurWhenTargetInvalidChar) {
	try {
		SimilarityChecker checker_except{ "abc" };
		FAIL();
	}
	catch (std::invalid_argument) {
		// PASS
	}	
}

TEST_F(SimilarityCheckerFixtrue, ExceptionOccurWhenInvalidChar) {
	EXPECT_THROW(checker.get_length_score("abc"), std::invalid_argument);
}
TEST_F(SimilarityCheckerFixtrue, Get60ScoreWhenMatchedLength) {
	EXPECT_EQ(checker.get_length_score("ABCED"), 60);
}
TEST_F(SimilarityCheckerFixtrue, Get0ScoreWhenLengthOvertwice) {
	EXPECT_EQ(checker.get_length_score("A"), 0);
	EXPECT_EQ(checker.get_length_score("AB"), 0);
	EXPECT_EQ(checker.get_length_score("ABCEDABCED"), 0);
	EXPECT_EQ(checker.get_length_score("ABCEDABCEDA"), 0);
}
TEST_F(SimilarityCheckerFixtrue, GetPartialScoreWhenLengthOvertwice) {
	EXPECT_EQ(checker.get_length_score("ABC"), 20);
}