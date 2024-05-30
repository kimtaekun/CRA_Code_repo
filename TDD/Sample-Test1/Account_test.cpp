#include "pch.h"
#include "../TDD/Account.cpp"

class AccountFixture : public testing::Test {
public:
	Account account{ 10000 };
};

TEST_F(AccountFixture, CreateAccountInit10000won) {	
	EXPECT_EQ(account.getBalance(), 10000);
}

TEST_F(AccountFixture, Deposit) {
	account.deposit(500);
	EXPECT_EQ(account.getBalance(), 10500);
}

TEST_F(AccountFixture, Withdraw) {
	account.withdraw(600);
	EXPECT_EQ(account.getBalance(), 9400);
}

TEST_F(AccountFixture, compound_interest_5percent) {
	account.interest();
	EXPECT_EQ(account.getBalance(), 10500);
	account.interest();
	EXPECT_EQ(account.getBalance(), 11025);
}

TEST_F(AccountFixture, interest_percent_set) {
	account.interest();
	EXPECT_EQ(account.getBalance(), 10500);
	account.interest_rate_set(10);
	account.interest();
	EXPECT_EQ(account.getBalance(), 11550);
}

TEST_F(AccountFixture, predict_interest_money) {
	account.interest_rate_set(10);
	EXPECT_EQ(account.get_predict_money(3), 13310);
}
