#include "validate_calc.cpp"

int main()
{
	//25+61=100
	//1 ~ 5�ڸ��� ���� ������ �´��� Ȯ���ϴ� ���α׷�
	//���� ����

	string str = "25+61=86"; //PASS
	//string str = "12345+12345=24690"; //PASS
	//string str = "5++5=10"; //ERROR
	//string str = "10000+1=10002"; //FAIL

	return 0;
}
