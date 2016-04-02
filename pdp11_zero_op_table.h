#ifndef PDP11_ZERO_OP_TABLE_H
#define PDP11_ZERO_OP_TABLE_H

//Zero operand instruction table

#include "pdp11_instruction.h"

namespace pdp11
{
    int HaltCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int NopCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    extern ZeroOperandInstruction Halt;
    extern ZeroOperandInstruction Nop;

    //wait and reset are not supported now
}

#endif // PDP11_ZERO_OP_TABLE_H

