#ifndef PDP11_ONE_OP_TABLE_H
#define PDP11_ONE_OP_TABLE_H

#include "pdp11_instruction.h"

namespace pdp11
{
    int ClrCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int ClrbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int IncCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int IncbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int DecCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int DecbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int AdcCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int AdcbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int SbcCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int SbcbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int TstCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int TstbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    int NegCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int NegbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    //ROR, ROL, ASR, ASL, SXT, COM are not supported now

    int SwabCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    extern OneOperandInstruction Clr;
    extern OneOperandInstruction Clrb;
    extern OneOperandInstruction Inc;
    extern OneOperandInstruction Incb;
    extern OneOperandInstruction Dec;
    extern OneOperandInstruction Decb;
    extern OneOperandInstruction Adc;
    extern OneOperandInstruction Adcb;
    extern OneOperandInstruction Sbc;
    extern OneOperandInstruction Sbcb;
    extern OneOperandInstruction Tst;
    extern OneOperandInstruction Tstb;
    extern OneOperandInstruction Neg;
    extern OneOperandInstruction Negb;
    extern OneOperandInstruction Swab;
}

#endif // PDP11_ONE_OP_TABLE_H

