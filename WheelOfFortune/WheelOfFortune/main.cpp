#include "wheel.cpp"

int main() {
	vector<string> strs;
	string userdata = "";
	int n = 0;

	freopen_s(new FILE*, "input2.txt", "r", stdin);
	cin >> n;

	//ют╥б
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;

	Wheel app;
	int price = app.getPrice(strs, userdata);

	cout << "$" << price << endl;
	return 0;
}
