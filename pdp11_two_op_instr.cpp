#include "pdp11_two_op_instr.h"

namespace pdp11
{
    int MovCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand src = alu.decodeWordOperand((instructionCode & 0xFC0) >> 6,
                                                    false, cpu, ram);

        Alu::Operand dst = alu.decodeWordOperand(instructionCode & 0x3F,
                                                 false, cpu, ram);

        dst.setWord(cpu, ram, src.getWord(cpu, ram, alu));

        cpu.getStatusWord().setNegative(static_cast<word>(src.getWord(cpu, ram, alu)) < 0);
        cpu.getStatusWord().setZero(src.getWord(cpu, ram, alu) == 0);
        cpu.getStatusWord().setOverflow(0);

        //register autoincrement
        if (src.registerNumber != -1)
        {
            cpu.setRegister(src.registerNumber, cpu.getRegister(src.registerNumber) + src.value);
        }

        return 0;
    }

    int MovbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand src = alu.decodeWordOperand((instructionCode & 0xFC0) >> 6,
                                                    true, cpu, ram);

        Alu::Operand dst = alu.decodeWordOperand(instructionCode & 0x3F,
                                                 true, cpu, ram);

        dst.setByte(cpu, ram, src.getByte(cpu, ram, alu));

        cpu.getStatusWord().setNegative(static_cast<byte>(src.getByte(cpu, ram, alu)) < 0);
        cpu.getStatusWord().setZero(src.getByte(cpu, ram, alu) == 0);
        cpu.getStatusWord().setOverflow(0);

        if (src.registerNumber != -1)
        {
            cpu.setRegister(src.registerNumber, cpu.getRegister(src.registerNumber) + src.value);
        }

        return 0;
    }

    int AddCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand src = alu.decodeWordOperand((instructionCode & 0xFC0) >> 6,
                                                    false, cpu, ram);

        Alu::Operand dst = alu.decodeWordOperand(instructionCode & 0x3F,
                                                 false, cpu, ram);

        dst.setWord(cpu, ram, alu.add(dst.getWord(cpu, ram, alu), src.getWord(cpu, ram, alu), cpu.getStatusWord()));

        if (src.registerNumber != -1)
        {
            cpu.setRegister(src.registerNumber, cpu.getRegister(src.registerNumber) + src.value);
        }

        return 0;
    }

    int SubCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand src = alu.decodeWordOperand((instructionCode & 0xFC0) >> 6,
                                                    false, cpu, ram);

        Alu::Operand dst = alu.decodeWordOperand(instructionCode & 0x3F,
                                                 false, cpu, ram);

        dst.setWord(cpu, ram, alu.sub(dst.getWord(cpu, ram, alu), src.getWord(cpu, ram, alu), cpu.getStatusWord()));

        if (src.registerNumber != -1)
        {
            cpu.setRegister(src.registerNumber, cpu.getRegister(src.registerNumber) + src.value);
        }

        return 0;
    }

    int CmpCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand src = alu.decodeWordOperand((instructionCode & 0xFC0) >> 6,
                                                    false, cpu, ram);

        Alu::Operand dst = alu.decodeWordOperand(instructionCode & 0x3F,
                                                 false, cpu, ram);

        alu.sub(src.getWord(cpu, ram, alu), dst.getWord(cpu, ram, alu), cpu.getStatusWord());

        if (src.registerNumber != -1)
        {
            cpu.setRegister(src.registerNumber, cpu.getRegister(src.registerNumber) + src.value);
        }

        if (dst.registerNumber != -1)
        {
            cpu.setRegister(dst.registerNumber, cpu.getRegister(dst.registerNumber) + dst.value);
        }

        return 0;
    }

    int CmpbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {

        Alu::Operand src = alu.decodeWordOperand((instructionCode & 0xFC0) >> 6,
                                                    false, cpu, ram);

        Alu::Operand dst = alu.decodeWordOperand(instructionCode & 0x3F,
                                                 false, cpu, ram);

        ubyte result = dst.getByte(cpu, ram, alu) - src.getByte(cpu, ram, alu);
        word wresult = static_cast<word>(dst.getByte(cpu, ram, alu)) - src.getByte(cpu, ram, alu);
        alu.setPsw(result, wresult, cpu.getStatusWord());

        if (src.registerNumber != -1)
        {
            cpu.setRegister(src.registerNumber, cpu.getRegister(src.registerNumber) + src.value);
        }

        if (dst.registerNumber != -1)
        {
            cpu.setRegister(dst.registerNumber, cpu.getRegister(dst.registerNumber) + dst.value);
        }

        return 0;
    }

    TwoOperandInstruction Mov("mov", 01, MovCmd);
    TwoOperandInstruction Movb("movb", 011, MovbCmd);
    TwoOperandInstruction Add("add", 06, AddCmd);
    TwoOperandInstruction Sub("sub", 016, SubCmd);
    TwoOperandInstruction Cmp("cmp", 02, CmpCmd);
    TwoOperandInstruction Cmpb("cmpb", 012, CmpbCmd);
}
