#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityCheckerTest, ExceptionOccurWhenInvalidChar) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.get_length_score("abc"), std::invalid_argument);
}