#include <limits>

#include "pdp11_alu.h"

using namespace pdp11;

uword Alu::bytesToWord(ubyte low, ubyte high) const
{
    return (static_cast<uword>(high) << 8) + low;
}

Alu::Operand Alu::decodeWordOperand(uword code, bool isByteInstruction, const Cpu &cpu, const Ram &ram)
{    
    //First half (bit 3-5) of addressing code
    const uword ADDRESSING_METHOD_MASK = 0x38;
    //Second half (bit 0-2) of addressing code
    const uword REGISTER_NUMBER_MASK = 0x7;

    uword addressingMethod = (code & ADDRESSING_METHOD_MASK) >> 3;
    uword registerNumber = code & REGISTER_NUMBER_MASK;

    Operand operand;

    if (addressingMethod == 0)
    {
        //register adressing
        operand.registerNumber = registerNumber;
    }
    else if (addressingMethod == 1)
    {
        //register inderect
        operand.memoryAdress = cpu.getRegister(registerNumber);
    }
    else if (addressingMethod == 2)
    {
        //autoincrement
        operand.registerNumber = registerNumber;

        if (!isByteInstruction || registerNumber > 5)
            operand.value = 2;
        else
            operand.value = 1;
    }
    else if (addressingMethod == 3)
    {
        //autoincrement inderect
        //do not forget about little-endian byte order
        operand.memoryAdress = bytesToWord(ram.get(cpu.getRegister(registerNumber)),
                                           ram.get(cpu.getRegister(registerNumber) + 1));

        if (!isByteInstruction || registerNumber > 5)
            operand.value = 2;
        else
            operand.value = 1;
    }
    else if (addressingMethod == 4)
    {
        //autodecrement
        operand.registerNumber = registerNumber;

        if (!isByteInstruction || registerNumber > 5)
            operand.value = -2;
        else
            operand.value = -1;
    }
    else if (addressingMethod == 5)
    {
        //autodecrement inderect
        operand.memoryAdress = bytesToWord(ram.get(cpu.getRegister(registerNumber)),
                                           ram.get(cpu.getRegister(registerNumber) + 1));

        if (!isByteInstruction || registerNumber > 5)
            operand.value = -2;
        else
            operand.value = -1;
    }
    else if (addressingMethod == 6)
    {
        //indexing
        operand.memoryAdress = cpu.getRegister(registerNumber) + cpu.getRegister(6);

        operand.registerNumber = 6;
        operand.value = 2;
    }
    else
    {
        //indexing inderect
        uword a = cpu.getRegister(registerNumber) + cpu.getRegister(6);;
        operand.memoryAdress = bytesToWord(ram.get(a), ram.get(a + 1));

        operand.registerNumber = 6;
        operand.value = 2;
    }

    return operand;
}

uword Alu::add(uword w1, uword w2, Psw *psw) const
{
    uword result = w1 + w2;

    dword dwordResult = (word)w1 + (word)w2;

    psw->setNegative((word)result < 0);
    psw->setZero(result == 0);
    psw->setCarry(result < w1);
    psw->setOverflow(dwordResult > std::numeric_limits<word>::max()
                     || dwordResult < std::numeric_limits<word>::min());

    return result;
}

uword Alu::sub(uword w1, uword w2, Psw *psw) const
{
    uword result = w1 - w2;

    dword dwordResult = (word)w1 - (word)w2;

    psw->setNegative((word)result < 0);
    psw->setZero(result == 0);
    psw->setCarry(w2 > w1);
    psw->setOverflow(dwordResult > std::numeric_limits<word>::max()
                     || dwordResult < std::numeric_limits<word>::min());

    return result;
}

uword Alu::logicalNot(uword w, Psw *psw) const
{
    uword result = ~w;

    psw->setNegative((word)result < 0);
    psw->setZero(result == 0);
    psw->setOverflow(0);
    psw->setCarry(1);

    return result;
}

uword Alu::logicalAnd(uword w1, uword w2, Psw *psw) const
{
    uword result = w1 & w2;

    psw->setNegative((word)result < 0);
    psw->setZero(result == 0);
    psw->setOverflow(0);
    //carry are not changed

    return result;
}

uword Alu::logicalOr(uword w1, uword w2, Psw *psw) const
{
    uword result = w1 | w2;

    psw->setNegative((word)result < 0);
    psw->setZero(result == 0);
    psw->setOverflow(0);
    //carry are not changed

    return result;
}

uword Alu::logicalXor(uword w1, uword w2, Psw *psw) const
{
    uword result = w1 ^ w2;

    psw->setNegative((word)result < 0);
    psw->setZero(result == 0);
    psw->setOverflow(0);
    //carry are not changed

    return result;
}
