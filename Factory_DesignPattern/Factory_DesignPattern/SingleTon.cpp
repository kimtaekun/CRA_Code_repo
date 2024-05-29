#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//static �޼��� : ��ü�������� ȣ��
//static �ʵ� : ��ü�������� ȣ��(�ܺμ����ʿ�)
//�޼��� �� static ���� : class ���� �ʵ� ����
class Logger {
public:
	static Logger& getInstance() {
		static Logger instance;
		return instance;
	}

	void Write(string log) {
		if (logFile.is_open()) {
			logFile << log << std::endl;
			std::cout << "Log written: " << log << std::endl;
		}
		else {
			std::cerr << "Unable to open log file." << std::endl;
		}
	}
private:
	Logger() {
		// �α� ���� ���� (append ���)
		logFile.open("log.txt", std::ios_base::app);
	}
	~Logger() {
		logFile.close();
	}
	Logger(const Logger& other) = delete;
	Logger& operator=(const Logger& other) = delete;

	std::ofstream logFile;
};
//
//int main() {
//	Logger& t1 = Logger::getInstance();
//	Logger& t2 = Logger::getInstance();
//
//	t1.Write("this is T1 Logger");
//	t2.Write("this is T2 Logger");
//}
