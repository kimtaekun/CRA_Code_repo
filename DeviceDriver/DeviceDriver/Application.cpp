#include <iostream>
#include "DeviceDriver.h"

class Application {
public:
	Application(DeviceDriver* device) : device_handle{ device } { }
	void ReadAndPrint(long startAddr, long endAddr) {
		for (long addr = startAddr; addr <= endAddr; addr++) {
			std::cout << device_handle->read(addr) << std::endl;
		}
	}
	void WriteAll(int value) {
		for (long addr = 0; addr <= 4; addr++) {
			device_handle->write(addr, value);
		}
	}
private:
	DeviceDriver* device_handle;
};