#ifndef PDP11_INSTR_LIST_H
#define PDP11_INSTR_LIST_H

//List of PDP-11 instructions. Because I can

#include <vector>

#include "pdp11_instruction.h"

namespace pdp11
{
    class InstructionList
    {
    public:
        InstructionList();

        Instruction *find(uword instructionCode);
        Instruction *find(const std::string &mnemonic);

    private:
        std::vector<Instruction*> _instructions;
    };
}

#endif // PDP11_INSTR_LIST_H

