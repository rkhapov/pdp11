#include <ctime>

#include "pdp11_system_unit.h"

pdp11::SystemUnit::SystemUnit(std::size_t memSize):
    _ram(memSize)
{
    _cpu.setRegister(0, 0);
    _cpu.setRegister(1, 0);
    _cpu.setRegister(2, 0);
    _cpu.setRegister(3, 0);
    _cpu.setRegister(4, 0);
    _cpu.setRegister(5, 0);
    _cpu.setRegister(6, 0);
    _cpu.setRegister(7, 0);
}

int pdp11::SystemUnit::executeNextInstruction()
{
    int returnCode = 0;

    try
    {
        //Receiving instruction code and move to the next
        //(possibly to the operands)
        uword code = _alu.bytesToWord(_ram.get(_cpu.getRegister(7)), _ram.get(_cpu.getRegister(7) + 1));
        _cpu.setRegister(7, _cpu.getRegister(7) + 2); //PC always increments with 2

        //find instruction
        Instruction *instruction = _instructionList.find(code);

        //if instruction was found, execute it
        if (instruction == nullptr)
        {
            returnCode = pdp11::UNKNOWN_INSTRUCTION;
        }
        else
        {
            returnCode = instruction->execute(code, _cpu, _ram, _alu);
        }
    }
    catch (std::out_of_range &e)
    {
        returnCode = pdp11::MEMORY_ADRESS_ERROR;
    }

    return returnCode;
}


void pdp11::SystemUnit::dump(std::ostream &stream) const
{
    //Time output
    std::time_t rawtime;
    std::time(&rawtime);
    std::tm *timeinfo = std::localtime(&rawtime);

    stream << "----- PDP-11 dump: " << std::asctime(timeinfo) << std::endl;

    //Dump Cpu
    stream << "Cpu:" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        stream << "\tRegister " << i << " -> "
               << std::hex << std::showbase << _cpu.getRegister(i) << std::endl;
    }

    stream << "\tPsw -> " << std::hex << std::showbase
           << _cpu.getStatusWord().getValue() << std::endl;

    //dump ram
    stream << "Ram:" << std::endl;
    _ram.dump(stream);
}
