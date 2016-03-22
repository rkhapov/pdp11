#ifndef ABSRT_CC_INSTRUCTION_H
#define ABSRT_CC_INSTRUCTION_H

//Abstract computer instruction type

#include <cstddef>

#include "abstr_cc_alu.h"
#include "abstr_cc_cpu.h"
#include "abstr_cc_memory.h"

namespace abstr_cc
{
    template <class Code_t, class InstructionCode_t, std::size_t size>
    class Instruction
    {
    public:
        Instruction(const Code_t &code, const InstructionCode_t &instructionCode):
            _code(code),
            _instructionCode(instructionCode)
        {}


        //size of instruction (in bytes)
        std::size_t getSize() const { return size; }

        virtual void execute() const = 0;

    private:
        Code_t _code;

        InstructionCode_t _instructionCode;
    };
}

#endif // ABSRT_CC_INSTRUCTION_H

