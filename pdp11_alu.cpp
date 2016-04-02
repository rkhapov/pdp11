#include <limits>

#include "pdp11_alu.h"

using namespace pdp11;

uword Alu::bytesToWord(ubyte low, ubyte high) const
{
    return (static_cast<uword>(high) << 8) | low;
}


void Alu::setPsw(ubyte value, word word16Value, Psw &psw) const
{
    psw.setNegative((byte)value < 0);
    psw.setZero(value == 0);
    psw.setCarry(word16Value > std::numeric_limits<ubyte>::max()); //unsigned overflow
    psw.setOverflow(word16Value > std::numeric_limits<byte>::max() //signed overflow
                     || word16Value < std::numeric_limits<byte>::min());
}

void Alu::setPsw(uword value, dword dword32Value, Psw &psw) const
{
    psw.setNegative((word)value < 0);
    psw.setZero(value == 0);
    psw.setCarry(dword32Value > std::numeric_limits<uword>::max());
    psw.setOverflow(dword32Value > std::numeric_limits<word>::max()
                     || dword32Value < std::numeric_limits<word>::min());
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

uword Alu::add(uword w1, uword w2, Psw &psw) const
{
    uword result = w1 + w2;

    dword dwordResult = (word)w1 + (word)w2;

    setPsw(result, dwordResult, psw);

    return result;
}

uword Alu::sub(uword w1, uword w2, Psw &psw) const
{
    return add(w1, -w2, psw);
}

uword Alu::logicalNot(uword w, Psw &psw) const
{
    uword result = ~w;

    psw.setNegative((word)result < 0);
    psw.setZero(result == 0);
    psw.setOverflow(0);
    psw.setCarry(1);

    return result;
}

uword Alu::logicalAnd(uword w1, uword w2, Psw &psw) const
{
    uword result = w1 & w2;

    psw.setNegative((word)result < 0);
    psw.setZero(result == 0);
    psw.setOverflow(0);
    psw.setCarry(0);

    return result;
}

uword Alu::logicalOr(uword w1, uword w2, Psw &psw) const
{
    uword result = w1 | w2;

    psw.setNegative((word)result < 0);
    psw.setZero(result == 0);
    psw.setOverflow(0);
    psw.setCarry(0);

    return result;
}

uword Alu::logicalXor(uword w1, uword w2, Psw &psw) const
{
    uword result = w1 ^ w2;

    psw.setNegative((word)result < 0);
    psw.setZero(result == 0);
    psw.setOverflow(0);
    psw.setCarry(0);

    return result;
}

void Alu::Operand::setByte(Cpu &cpu, Ram &ram, ubyte val)
{
    if (memoryAdress != -1 && registerNumber == -1)
    {
        ram.set(memoryAdress, val);
    }
    else if (registerNumber != -1 && memoryAdress == -1)
    {
        cpu.setRegister(registerNumber, (cpu.getRegister(registerNumber) & 0xFF00) | (uword)val);
        cpu.setRegister(registerNumber, cpu.getRegister(registerNumber) + value);
    }
    else
    {
        ram.set(memoryAdress, val);
        cpu.setRegister(registerNumber, cpu.getRegister(registerNumber) + value);
    }
}

void Alu::Operand::setWord(Cpu &cpu, Ram &ram, uword val)
{
    if (memoryAdress != -1 && registerNumber == -1)
    {
        //do not forget about little-endian!
        ram.set(memoryAdress, (ubyte)val); //low byte
        ram.set(memoryAdress + 1, (ubyte)(val >> 8)); //high byte
    }
    else if (registerNumber != -1 && memoryAdress == -1)
    {
        cpu.setRegister(registerNumber, value);
        cpu.setRegister(registerNumber, cpu.getRegister(registerNumber) + value);
    }
    else
    {
        ram.set(memoryAdress, (ubyte)val);
        ram.set(memoryAdress + 1, (ubyte)(val >> 8));
        cpu.setRegister(registerNumber, cpu.getRegister(registerNumber) + value);
    }
}
uword Alu::Operand::getWord(Cpu &cpu, Ram &ram, Alu &alu) const
{
    if (memoryAdress != -1)
    {
        return alu.bytesToWord(ram.get(memoryAdress), ram.get(memoryAdress + 1));
    }
    return cpu.getRegister(registerNumber);
}

ubyte Alu::Operand::getByte(Cpu &cpu, Ram &ram, Alu &alu __attribute__((unused))) const
{
    if (memoryAdress != -1)
    {
        return ram.get(memoryAdress);
    }

    return static_cast<ubyte>(cpu.getRegister(registerNumber));
}

uword *Alu::Operand::getWordPointer(Cpu &cpu, Ram &ram) const
{
    if (memoryAdress != -1)
    {
        return reinterpret_cast<uword*>(&ram.get(memoryAdress));
    }
    return &cpu.getRegister(registerNumber);
}

ubyte *Alu::Operand::getBytePointer(Cpu &cpu, Ram &ram) const
{
    if (memoryAdress != -1)
    {
        return &ram.get(memoryAdress);
    }

    return reinterpret_cast<ubyte*>(cpu.getRegister(registerNumber));
}
