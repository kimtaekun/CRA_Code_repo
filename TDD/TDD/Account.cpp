class Account {
public:
	Account(int _balance)
		: balance{ _balance }, interest_rate{ 5 } {}

	int getBalance() {
		return balance;
	}
	
	void deposit(int money) {
		balance += money;
	}
	void withdraw(int money) {
		balance -= money;
	}
	void interest() {
		balance += balance * (interest_rate / 100.0);
	}

	void interest_rate_set(int percent) {
		interest_rate = percent;
	}

	int get_predict_money(int year) {
		int init_money = balance;
		for (int i = 0; i < year; i++) {
			init_money += init_money * (interest_rate / 100.0);
		}
		return init_money;
	}
private:
	int balance;
	int interest_rate;
};