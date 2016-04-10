#ifndef PDP11_SYSTEM_UNIT_H
#define PDP11_SYSTEM_UNIT_H

//SystemUnit - unit of PDP11 which contains cpu, alu and ram
//Enough to have one copy of this class to start use PDP-11

#include <vector>

#include "pdp11_cpu.h"
#include "pdp11_alu.h"
#include "pdp11_ram.h"
#include "pdp11_instr_list.h"

namespace pdp11
{
    class SystemUnit
    {
    public:
        SystemUnit(std::size_t memSize);

        //returs pdp11::HALT for halt machine
        //and pdp11::MEMORY_ADDRESS_ERROR for bad address
        int executeNextInstruction();

        void dump(std::ostream &stream) const;

        Cpu &getCpu() { return _cpu; }
        const Cpu &getCpu() const { return _cpu; }

        Ram &getRam() { return _ram; }
        const Ram &getRam() const { return _ram; }

        Alu &getAlu() { return _alu; }
        const Alu &getAlu() const { return _alu; }

    private:
        Cpu _cpu;
        Ram _ram;
        Alu _alu;

        InstructionList _instructionList;
    };
}

#endif // PDP11_SYSTEM_UNIT_H

