#ifndef PDP11_PSW_INSTR_H
#define PDP11_PSW_INSTR_H

/*
 * Instructions to control Psw
*/

#include "pdp11_instruction.h"

namespace pdp11
{
    int ClcCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int ClvCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int ClzCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int ClnCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int CccCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int SecCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int SevCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int SezCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int SenCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int SccCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    extern ZeroOperandInstruction Clc;
    extern ZeroOperandInstruction Clv;
    extern ZeroOperandInstruction Clz;
    extern ZeroOperandInstruction Cln;
    extern ZeroOperandInstruction Ccc;

    extern ZeroOperandInstruction Sec;
    extern ZeroOperandInstruction Sev;
    extern ZeroOperandInstruction Sez;
    extern ZeroOperandInstruction Sen;
    extern ZeroOperandInstruction Scc;
}

#endif // PDP11_PSW_INSTR_H

