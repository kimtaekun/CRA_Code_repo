#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityCheckerTest, ExceptionOccurWhenInvalidChar) {
	SimilarityChecker checker{ "ABC" };
	EXPECT_THROW(checker.get_length_score("abc"), std::invalid_argument);
}
TEST(SimilarityCheckerTest, Get60ScoreWhenMatchedLength) {
	SimilarityChecker checker{ "ABC" };
	EXPECT_EQ(checker.get_length_score("ABC"), 60);
}