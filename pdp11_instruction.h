#ifndef PDP11_INSTRUCTION_H
#define PDP11_INSTRUCTION_H

/*
 * PDP-11 Instruction.
 * There are Abstract class Instruction and
 * - ZeroOperandInstruction - instruction which have no perametrs (as Nop and Ccc)
 * - OneOperandInstruction - instruction which have one parametr
 * - BranchInstruction - branch instruction with one parameter - offset
 * - OneAndHalfOperand - one operand and some register (such as MUL) - not used on this version
 * - TwoOperandInstruction - two operand (as Mov)
*/

#include <string>

#include "pdp11_types.h"
#include "pdp11_alu.h"
#include "pdp11_cpu.h"
#include "pdp11_ram.h"

#include "abstr_cc_instruction.h"

namespace pdp11
{
    //Type of instruction commands
    enum { HALT = 1, DIVISION_BY_ZERO, MEMORY_ADRESS_ERROR, UNKNOWN_INSTRUCTION };
    typedef int (*InstructionCmd)(uword, Cpu&, Ram&, Alu&);

    class Instruction: public abstr_cc::Instruction<uword, InstructionCmd, 2>
    {
    public:
        virtual ~Instruction() {}

        Instruction(const std::string &mnemonic, uword code, InstructionCmd cmd):
            abstr_cc::Instruction<uword, InstructionCmd, 2>(code, cmd),
            _mnemonic(mnemonic)
        {}

        //returns true, if code are equally with this instruction
        //(not only instructionCode == this->getCode())
        //and false in other way
        virtual bool checkCode(uword instructionCode) const = 0;

        int execute(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu) const
        { return (getCmd())(instructionCode, cpu, ram, alu); }

        const std::string &getMnemonic() const { return _mnemonic; }

    private:
        std::string _mnemonic;
    };


    class ZeroOperandInstruction: public Instruction
    {
    public:
        ZeroOperandInstruction(const std::string &mnemonic, uword code, InstructionCmd cmd):
            Instruction(mnemonic, code, cmd)
        {}

        bool checkCode(uword instructionCode) const { return instructionCode == getCode(); }
    };


    class OneOperandInstruction: public Instruction
    {
    public:
        OneOperandInstruction(const std::string &mnemonic, uword code, InstructionCmd cmd):
            Instruction(mnemonic, code, cmd)
        {}

        bool checkCode(uword instructionCode) const
        {
            //One operand instructions keeps the code in 15..6 bits
            //therefore instructionCode must be right-shifted at 6 bit
            return (instructionCode >> 6) == getCode();
        }
    };

    class OneAndHalfOperandInstruction: public Instruction
    {
    public:
        OneAndHalfOperandInstruction(const std::string &mnemonic, uword code, InstructionCmd cmd):
            Instruction(mnemonic, code, cmd)
        {}

        bool checkCode(uword instructionCode) const
        {
            //One and half operand instruction keeps code in 15..9 bits
            return (instructionCode >> 9) == getCode();
        }
    };


    class TwoOperandInstruction: public Instruction
    {
    public:
        TwoOperandInstruction(const std::string &mnemonic, uword code, InstructionCmd cmd):
            Instruction(mnemonic, code, cmd)
        {}

        bool checkCode(uword instructionCode) const
        {
            //Instruction keeps code in 15..12 bits
            return (instructionCode >> 12) == getCode();
        }
    };

    class BranchInstruction: public Instruction
    {
    public:
        BranchInstruction(const std::string &mnemonic, uword code, InstructionCmd cmd):
            Instruction(mnemonic, code, cmd)
        {}

        bool checkCode(uword instructionCode) const
        {
            return (instructionCode >> 8) == getCode();
        }
    };
}

#endif // PDP11_INSTRUCTION_H

