#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../DeviceDriver/Application.cpp"

using namespace testing;

class FlashMemoryDeviceMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long), (override));
	MOCK_METHOD(void, write, (long, unsigned char), (override));
};

class ApplicationFixture : public testing::Test {
public:
	FlashMemoryDeviceMock memory;
	DeviceDriver driver{ &memory };
	Application app{ &driver };
};

TEST_F(ApplicationFixture, ReadAndPrint_0to2Address) {
	EXPECT_CALL(memory, read(0))
		.Times(5)
		.WillRepeatedly(Return(0x02));
	EXPECT_CALL(memory, read(1))
		.Times(5)
		.WillRepeatedly(Return(0x03));
	EXPECT_CALL(memory, read(2))
		.Times(5)
		.WillRepeatedly(Return(0x04));
	app.ReadAndPrint(0, 2);
}

TEST_F(ApplicationFixture, WriteAll_value0x23) {
	EXPECT_CALL(memory, read(0))
		.Times(1)
		.WillOnce(Return(0xff));
	EXPECT_CALL(memory, write(0, 0x23))
		.Times(1);

	EXPECT_CALL(memory, read(1))
		.Times(1)
		.WillOnce(Return(0xff));
	EXPECT_CALL(memory, write(1, 0x23))
		.Times(1);

	EXPECT_CALL(memory, read(2))
		.Times(1)
		.WillOnce(Return(0xff));
	EXPECT_CALL(memory, write(2, 0x23))
		.Times(1);

	EXPECT_CALL(memory, read(3))
		.Times(1)
		.WillOnce(Return(0xff));
	EXPECT_CALL(memory, write(3, 0x23))
		.Times(1);

	EXPECT_CALL(memory, read(4))
		.Times(1)
		.WillOnce(Return(0xff));
	EXPECT_CALL(memory, write(4, 0x23))
		.Times(1);

	app.WriteAll(0x23);
}
