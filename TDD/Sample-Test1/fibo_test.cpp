#include <vector>

#include "pch.h"
#include "../TDD/fibo.cpp"

TEST(FiboTest, OrderTest) {
	std::vector<std::pair<int, int>> cases{ {0,0}, {1,1}, {2,1}, {3,2} };
	for (auto val : cases) {
		EXPECT_EQ(val.second, Fibo().fibo(val.first));
	}
}
