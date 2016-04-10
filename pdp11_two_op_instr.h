#ifndef PDP11_TWO_OP_INSTR_H
#define PDP11_TWO_OP_INSTR_H

/*
 * Two operand instructions
 * bit instruction are not supported now
*/

#include "pdp11_instruction.h"

namespace pdp11
{
    int MovCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int MovbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int AddCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int SubCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int CmpCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int CmpbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    extern TwoOperandInstruction Mov;
    extern TwoOperandInstruction Movb;
    extern TwoOperandInstruction Add;
    extern TwoOperandInstruction Sub;
    extern TwoOperandInstruction Cmp;
    extern TwoOperandInstruction Cmpb;
}

#endif // PDP11_TWO_OP_INSTR_H

