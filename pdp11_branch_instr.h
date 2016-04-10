#ifndef PDP11_BRANCH_INSTR_H
#define PDP11_BRANCH_INSTR_H

#include "pdp11_instruction.h"

namespace pdp11
{
    int BrCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BrneCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BeqCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BplCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BmiCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BvcCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BvsCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BccCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);
    int BcsCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu);

    //other branch instaruction are not supported now

    extern BranchInstruction Br;
    extern BranchInstruction Brne;
    extern BranchInstruction Beq;
    extern BranchInstruction Bpl;
    extern BranchInstruction Bmi;
    extern BranchInstruction Bvc;
    extern BranchInstruction Bvs;
    extern BranchInstruction Bcc;
    extern BranchInstruction Bcs;
}

#endif // PDP11_BRANCH_INSTR_H

