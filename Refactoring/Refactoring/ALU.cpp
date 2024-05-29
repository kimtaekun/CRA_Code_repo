#pragma once

#include <string>
#include <optional>
#define interface struct


class Result
{
public:
    enum class enumStatus : int {
        None = -1,
        Success,
        Operand_1_Err,
        Operand_2_Err,
        OPCode_Err,
    };
    void setStatus(enumStatus status) {
        this->status = status;
    }    
    void setStatus(int status) {
        this->status = static_cast<enumStatus>(status);
    }

    void setResult(int result) {
        this->result = result;
    }

    int getStatus() {
        return static_cast<int>(status);
    }

    int getResult() {
        return result;
    }

private:
    //result 65535 : 결과 없음
    int result = 65535;
    enumStatus status = enumStatus::None;
};


struct ALU_param {
    int operand1 = -1;
    int operand2 = -1;

    std::optional<int> validate_operand() {
        if (operand1 == -1) return 1;
        if (operand2 == -1) return 2;
        return std::nullopt;
    }
};
interface OperatorMethod {
    virtual int getResult(ALU_param param) = 0;
};
class ADDMethod : public OperatorMethod {
public:
    int getResult(ALU_param param) override {
        return param.operand1 + param.operand2;
    }
};
class MULMethod : public OperatorMethod {
public:
    int getResult(ALU_param param) override {
        return param.operand1 * param.operand2;
    }
};
class SUBMethod : public OperatorMethod {
public:
    int getResult(ALU_param param) override {
        return param.operand1 - param.operand2;
    }
};
class ALU
{public:
    void enableSignal(Result* r) {
        auto operand_error = Param.validate_operand();
        if (operand_error.has_value()) {
            r->setStatus(operand_error.value());
            r->setResult(65535);
            return;
        }

        if (GetOPMethod() == false) {
            r->setResult(65535);
            r->setStatus(Result::enumStatus::OPCode_Err);
            return;
        }

        r->setResult(OPMethod->getResult(Param));
        r->setStatus(Result::enumStatus::Success);
    }

    void setOperand1(int operand1) {
        Param.operand1 = operand1;
    }

    void setOperand2(int operand2) {
        Param.operand2 = operand2;
    }

    void setOPCODE(std::string OPCODE) {
        this->OPCODE = OPCODE;
    }
private:
    ALU_param Param;
    std::string OPCODE;

    OperatorMethod* OPMethod = nullptr;
    bool GetOPMethod() {
        if (OPCODE == "ADD") {
            OPMethod = new ADDMethod();
        }
        else if (OPCODE == "MUL") {
            OPMethod = new MULMethod();
        }
        else if (OPCODE == "SUB") {
            OPMethod = new SUBMethod();
        }

        if (OPMethod == nullptr)
            return false;
        return true;
    }
};

