#include "DeviceDriver.h"
#include <stdexcept>
#include <string>

class ReadFailException : public std::logic_error {
public:
    using _Mybase = logic_error;
    explicit ReadFailException(const std::string& _Message) : _Mybase(_Message.c_str()) {}
    explicit ReadFailException(const char* _Message) : _Mybase(_Message) {}
};
class WriteFailException : public std::logic_error {
public:
    using _Mybase = logic_error;
    explicit WriteFailException(const std::string& _Message) : _Mybase(_Message.c_str()) {}
    explicit WriteFailException(const char* _Message) : _Mybase(_Message) {}
};

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    unsigned char read_data = m_hardware->read(address);
    for (int i = 0; i < 4; i++) {
        if (read_data != m_hardware->read(address))
            throw ReadFailException("read 5 count but not same value");
    }
    return read_data;
}

void DeviceDriver::write(long address, int data)
{
    if (m_hardware->read(address) != 0xff) {
        throw WriteFailException("this address not empty");
    }
    m_hardware->write(address, (unsigned char)data);
}