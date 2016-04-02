#include "pdp11_zero_op_table.h"

int pdp11::HaltCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
                   Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
{
    //Halt machine
    return pdp11::HALT;
}

int pdp11::NopCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
                  Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
{
    //Nothing operates
    return 0;
}

pdp11::ZeroOperandInstruction Halt("halt", 0, pdp11::HaltCmd);
pdp11::ZeroOperandInstruction Nop("nop", 0240, pdp11::NopCmd);
