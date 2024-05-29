#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::vector;

int getSum(std::vector<int>& values)
{
	int ret = 0;
	for (int i = 0; i < values.size(); i++) {
		int temp = values[i];
		ret += temp;
	}
	return ret;
}

vector<int> TextSplit(std::string& text)
{
	vector<int> ret;
	text += "-";
	int a = 0, b = 0;
	while (1) {
		b = text.find("-", a);
		if (b == -1) break;
		string temp = text.substr(a, b - a);
		ret.push_back(stoi(temp));
		a = b + 1;
	}
	return ret;
}

int splitAndSum(string text)
{
	if (text.empty())
	{
		return 0;
	}

	vector<int> values = TextSplit(text);
	return getSum(values);
}
