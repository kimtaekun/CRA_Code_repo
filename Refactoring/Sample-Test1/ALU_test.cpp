#include "pch.h"
#include "../Refactoring/ALU.cpp";

TEST(ALU, ADDTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(30, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}
TEST(ALU, MULTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(200, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}
TEST(ALU, SUBTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(-10, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}
TEST(ALU, InvalidOPCodeTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("DIV");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(3, ret.getStatus());
}
TEST(ALU, ADDInvalioperand1Test) {
	ALU alu;
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}
TEST(ALU, ADDInvalioperand2Test) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}
TEST(ALU, MULInvalioperand1Test) {
	ALU alu;
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}
TEST(ALU, MULInvalioperand2Test) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}
TEST(ALU, SUBInvalioperand1Test) {
	ALU alu;
	alu.setOperand2(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}
TEST(ALU, SUBInvalioperand2Test) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}