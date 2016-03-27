#ifndef ABSRT_CC_INSTRUCTION_H
#define ABSRT_CC_INSTRUCTION_H

//Abstract computer instruction type

#include <cstddef>

#include "abstr_cc_alu.h"
#include "abstr_cc_cpu.h"
#include "abstr_cc_memory.h"

namespace abstr_cc
{
    template <class Code_t, class InstructionCmd_t, std::size_t size>
    class Instruction
    {
    public:
        Instruction(const Code_t &code, const InstructionCmd_t &instructionCmd):
            _code(code),
            _instructionCmd(instructionCmd)
        {}


        //size of instruction (in bytes)
        std::size_t getSize() const { return size; }

        virtual void execute() const = 0;

        const InstructionCmd_t &getCmd() const { return _instructionCmd; }

    private:
        Code_t _code;

        InstructionCmd_t _instructionCmd;
    };
}

#endif // ABSRT_CC_INSTRUCTION_H

