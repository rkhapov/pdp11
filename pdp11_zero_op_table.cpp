#include "pdp11_zero_op_table.h"

namespace pdp11
{

    int HaltCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
                Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        //Halt machine
        return pdp11::HALT;
    }

    int NopCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        //Nothing operates
        return 0;
    }

    ZeroOperandInstruction Halt("halt", 0, HaltCmd);
    ZeroOperandInstruction Nop("nop", 0240, NopCmd);

}
