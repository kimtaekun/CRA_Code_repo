#pragma once
#include <string>
using std::string;

class Movie
{
public:
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;
	static const int CHILDRENS = 2;

	Movie(const string& title, int price_code)
		: title(title),
		priceCode(price_code)
	{
	}

	int getPriceCode()
	{
		return priceCode;
	}

	void setPriceCode(int price_code)
	{
		priceCode = price_code;
	}

	string getTitle()
	{
		return title;
	}

	double getChargeFor(int daysRented) {
		double thisAmount = 0;
		switch (getPriceCode())
		{
		case REGULAR:
			thisAmount += 2;
			if (daysRented > 2) {
				thisAmount += (daysRented - 2) * 1.5;
			}
			break;
		case NEW_RELEASE:
			thisAmount += daysRented * 3;
			break;
		case CHILDRENS:
			thisAmount += 1.5;
			if (daysRented > 3) {
				thisAmount += (daysRented - 3) * 1.5;
			}
			break;
		}
		return thisAmount;
	}
	int getFrequentRetalPointsFor(int daysRented)
	{
		if (getPriceCode() == Movie::NEW_RELEASE && daysRented > 1) {
			return 2;
		}
		return 1;
	}
private:
	string title;
	int priceCode;
};
