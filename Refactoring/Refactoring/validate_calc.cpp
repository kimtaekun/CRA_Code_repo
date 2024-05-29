#include <string>
#include <vector>
#include <iostream>
#include <optional>
using namespace std;

class Validate_Calc {
public:
	std::string getResult(std::string formula) {
		Calc_Formula convert_formula;
		if (validate_formula(formula, convert_formula) == false) {
			return "ERROR";
		}

		if (convert_formula.first_number + convert_formula.second_number 
			== convert_formula.result) {
			return "PASS";
		}
		return "FAIL";
	}

private:
	class Calc_Formula {
	public:
		int first_number = 0;
		int second_number = 0;
		int result = 0;
	};
	bool validate_formula(std::string formula, Calc_Formula& ret) {
		std::optional<int> plus_pos = operator_cnt_validate(formula, "+");
		std::optional<int> equal_pos = operator_cnt_validate(formula, "=");
		if (plus_pos.has_value() == false || equal_pos.has_value() == false) {
			return false;
		}
		
		if (operator_pos_validate(plus_pos.value(), equal_pos.value(), formula.length()) == false) {
			return false;
		}
		
		try {
			ret = Convert_Formula(formula, plus_pos.value(), equal_pos.value());
		}
		catch (std::exception& e) {
			return false;
		}
		return true;
	}

	std::optional<int> operator_cnt_validate(std::string& formula, std::string operator_char) {
		std::size_t found = formula.find(operator_char);
		if (found == std::string::npos) {
			return std::nullopt;
		}

		std::size_t second_plus_pos = formula.find(operator_char, found + 1);
		if (second_plus_pos != std::string::npos)
		{
			return std::nullopt;
		}
		return found;
	}

	bool operator_pos_validate(int plus_pos, int equal_pos, int formula_length)
	{
		if (plus_pos > equal_pos) {
			return false;
		}
		if ((plus_pos >= 1 && equal_pos >= 3) == false) {
			return false;
		}
		if (equal_pos >= formula_length - 1) {
			return false;
		}
		return true;
	}

	Calc_Formula Convert_Formula(std::string& formula, int plus_pos, int equal_pos)
	{
		Calc_Formula ret;
		ret.first_number = stoi(formula.substr(0, plus_pos));
		ret.second_number = stoi(formula.substr(plus_pos + 1, equal_pos - plus_pos - 1));
		ret.result = stoi(formula.substr(equal_pos + 1));
		return ret;
	}
};