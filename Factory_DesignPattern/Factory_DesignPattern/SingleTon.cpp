#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//static 메서드 : 객체생성없이 호출
//static 필드 : 객체생성없이 호출(외부선언필요)
//메서드 내 static 변수 : class 내부 필드 개념
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
		// 로그 파일 열기 (append 모드)
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
