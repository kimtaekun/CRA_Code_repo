#include <vector>
#include <string>
#include <sstream>

class Movie {
private:
	std::string _title;
	int _priceCode;

public:
	static const int CHILDRENS = 2;
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;

	Movie(std::string title, int priceCode)
		: _title(title), _priceCode(priceCode) {
	}
	std::string getTitle() const {
		return _title;
	}

	int getPriceCode() const {
		return _priceCode;
	}
	void setPriceCode(int priceCode) {
		_priceCode = priceCode;
	}
};

class Rental {
private:
	Movie _movie;
	int _daysRented;

public:
	Rental(const Movie& movie, int daysRented) 
		: _movie(movie), _daysRented(daysRented) {
	}

	int getDaysRented() const {
		return _daysRented;
	}
	const Movie& getMovie() const {
		return _movie;
	}
};

class Customer {
private:
	std::string _name;
	std::vector<Rental> _rentals;

public:
	Customer(std::string name)
		: _name(name) {
	}

	std::string getName() const {
		return _name;
	}
	void addRental(const Rental& rental) {
		_rentals.push_back(rental);
	}

	std::string statement() const {
		std::string result = "Rental Record for " + getName() + "\n";

		double totalAmount = 0;
		int frequentRenterPoints = 0;

		std::vector<Rental>::const_iterator it;
		for (it = _rentals.begin(); it != _rentals.end(); ++it) {
			double thisAmount = 0;
			const Rental& each = *it;

			switch (each.getMovie().getPriceCode())
			{
			case Movie::REGULAR:
				thisAmount += 2;
				if (each.getDaysRented() > 2) {
					thisAmount += (each.getDaysRented() - 2) * 1.5;
				}
				break;

			case Movie::CHILDRENS:
				thisAmount += 1.5;
				if (each.getDaysRented() > 3) {
					thisAmount += (each.getDaysRented() - 3) * 1.5;
				}
				break;

			case Movie::NEW_RELEASE:
				thisAmount += each.getDaysRented() * 3;
				break;
			}

			frequentRenterPoints++;
			if (each.getMovie().getPriceCode() == Movie::NEW_RELEASE && each.getDaysRented() > 1) {
				frequentRenterPoints++;
			}

			std::ostringstream stream;
			stream << "\t" << each.getMovie().getTitle();
			stream << "\t" << thisAmount << "\n";
			result += stream.str();
			totalAmount += thisAmount;
		}

		std::ostringstream stream;
		stream << "You owed " << totalAmount << "\n";
		stream << "You earned " << frequentRenterPoints << " frequent renter points";
		result += stream.str();

		return result;
	}
};
