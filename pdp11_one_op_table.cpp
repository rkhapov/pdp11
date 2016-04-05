#include "pdp11_one_op_table.h"

namespace pdp11
{
    int ClrCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        cpu.getStatusWord().setCarry(0);
        cpu.getStatusWord().setNegative(0);
        cpu.getStatusWord().setOverflow(0);
        cpu.getStatusWord().setZero(1);

        operand.setWord(cpu, ram, 0);

        return 0;

    }
    int ClrbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);
        cpu.getStatusWord().setCarry(0);
        cpu.getStatusWord().setNegative(0);
        cpu.getStatusWord().setOverflow(0);
        cpu.getStatusWord().setZero(1);

        operand.setByte(cpu, ram, 0);

        return 0;
    }

    int IncCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        //carry is not affected
        bool carry = cpu.getStatusWord().getCarry();

        alu.setPsw(operand.getWord(cpu, ram, alu) + 1,
                   static_cast<dword>(operand.getWord(cpu, ram, alu)) + 1, cpu.getStatusWord());

        operand.setWord(cpu, ram, operand.getWord(cpu, ram, alu) + 1);

        cpu.getStatusWord().setCarry(carry);

        return 0;
    }

    int IncbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);

        //carry is not affected
        bool carry = cpu.getStatusWord().getCarry();

        alu.setPsw(static_cast<ubyte>(operand.getByte(cpu, ram, alu) + 1),
                   static_cast<word>(operand.getByte(cpu, ram, alu)) + 1, cpu.getStatusWord());

        operand.setByte(cpu, ram, operand.getByte(cpu, ram, alu) + 1);

        cpu.getStatusWord().setCarry(carry);

        return 0;
    }

    int DecCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        bool carry = cpu.getStatusWord().getCarry();

        alu.setPsw(operand.getWord(cpu, ram, alu) - 1,
                   static_cast<dword>(operand.getWord(cpu, ram, alu) - 1), cpu.getStatusWord());

        operand.setWord(cpu, ram, operand.getWord(cpu, ram, alu) - 1);

        cpu.getStatusWord().setCarry(carry);


        return 0;
    }

    int DecbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);

        bool carry = cpu.getStatusWord().getCarry();

        alu.setPsw(static_cast<ubyte>(operand.getByte(cpu, ram, alu) - 1),
                   static_cast<word>(operand.getWord(cpu, ram, alu) - 1), cpu.getStatusWord());

        operand.setByte(cpu, ram, operand.getByte(cpu, ram, alu) - 1);

        cpu.getStatusWord().setCarry(carry);

        return 0;
    }

    int AdcCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        alu.setPsw(operand.getWord(cpu, ram, alu) + cpu.getStatusWord().getCarry(),
                   static_cast<dword>(operand.getWord(cpu, ram, alu))
                   + cpu.getStatusWord().getCarry(), cpu.getStatusWord());

        operand.setWord(cpu, ram, operand.getWord(cpu, ram, alu) + cpu.getStatusWord().getCarry());

        return 0;
    }

    int AdcbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {

        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);

        alu.setPsw(static_cast<ubyte>(operand.getByte(cpu, ram, alu) + cpu.getStatusWord().getCarry()),
                   static_cast<word>(operand.getByte(cpu, ram, alu))
                   + cpu.getStatusWord().getCarry(), cpu.getStatusWord());

        operand.setByte(cpu, ram, operand.getByte(cpu, ram, alu));

        return 0;
    }

    int SbcCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        alu.setPsw(operand.getWord(cpu, ram, alu) - cpu.getStatusWord().getCarry(),
                   static_cast<dword>(operand.getWord(cpu, ram, alu))
                   - cpu.getStatusWord().getCarry(), cpu.getStatusWord());

        operand.setWord(cpu, ram, operand.getWord(cpu, ram, alu) - cpu.getStatusWord().getCarry());

        return 0;
    }

    int SbcbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);

        alu.setPsw(static_cast<ubyte>(operand.getByte(cpu, ram, alu) - cpu.getStatusWord().getCarry()),
                   static_cast<word>(operand.getByte(cpu, ram, alu))
                   - cpu.getStatusWord().getCarry(), cpu.getStatusWord());

        operand.setByte(cpu, ram, operand.getByte(cpu, ram, alu));

        return 0;
    }

    int TstCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        cpu.getStatusWord().setCarry(0);
        cpu.getStatusWord().setOverflow(0);

        cpu.getStatusWord().setNegative(static_cast<word>(operand.getWord(cpu, ram, alu)) < 0);
        cpu.getStatusWord().setZero(operand.getWord(cpu, ram, alu) == 0);

        if (operand.registerNumber != -1)
        {
            cpu.setRegister(operand.registerNumber,
                            cpu.getRegister(operand.registerNumber) + operand.value);
        }

        return 0;
    }

    int TstbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);

        cpu.getStatusWord().setCarry(0);
        cpu.getStatusWord().setOverflow(0);

        cpu.getStatusWord().setNegative(static_cast<byte>(operand.getByte(cpu, ram, alu)) < 0);
        cpu.getStatusWord().setZero(operand.getByte(cpu, ram, alu) == 0);

        if (operand.registerNumber != -1)
        {
            cpu.setRegister(operand.registerNumber,
                            cpu.getRegister(operand.registerNumber) + operand.value);
        }

        return 0;
    }

    int NegCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        uword newValue = -operand.getWord(cpu, ram, alu);

        cpu.getStatusWord().setNegative(static_cast<word>(newValue) < 0);
        cpu.getStatusWord().setZero(newValue == 0);
        cpu.getStatusWord().setCarry(newValue == 0);
        cpu.getStatusWord().setOverflow(operand.getWord(cpu, ram, alu) == 0x8000);

        operand.setWord(cpu, ram, newValue);

        return 0;
    }


    int NegbCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {

        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     true, cpu, ram);

        ubyte newValue = -operand.getByte(cpu, ram, alu);

        cpu.getStatusWord().setNegative(static_cast<byte>(newValue) < 0);
        cpu.getStatusWord().setZero(newValue == 0);
        cpu.getStatusWord().setCarry(newValue == 0);
        cpu.getStatusWord().setOverflow(operand.getByte(cpu, ram, alu) == 0x80);

        operand.setByte(cpu, ram, newValue);

        return 0;

    }

    int SwabCmd(uword instructionCode, Cpu &cpu, Ram &ram, Alu &alu)
    {
        Alu::Operand operand = alu.decodeWordOperand(instructionCode & 0x1F,
                                                     false, cpu, ram);

        uword result = operand.getWord(cpu, ram, alu);
        result = (result >> 8) | (result << 8);

        cpu.getStatusWord().setCarry(0);
        cpu.getStatusWord().setOverflow(0);
        cpu.getStatusWord().setNegative((byte)result < 0);
        cpu.getStatusWord().setZero((ubyte)result == 0);

        operand.setWord(cpu, ram, result);

        return 0;
    }

    OneOperandInstruction Clr("clr", 050, ClrCmd);
    OneOperandInstruction Clrb("clrb", 01050, ClrbCmd);

    OneOperandInstruction Inc("inc", 052, IncCmd);
    OneOperandInstruction Incb("incb", 01052, IncbCmd);

    OneOperandInstruction Dec("dec", 053, DecCmd);
    OneOperandInstruction Decb("decb", 01053, DecbCmd);

    OneOperandInstruction Adc("adc", 055, AdcCmd);
    OneOperandInstruction Adcb("adcb", 01055, AdcbCmd);

    OneOperandInstruction Sbc("sbc", 056, SbcCmd);
    OneOperandInstruction Sbcb("sbcb", 01056, SbcbCmd);

    OneOperandInstruction Tst("tst", 057, TstCmd);
    OneOperandInstruction Tstb("tstb", 01057, TstbCmd);

    OneOperandInstruction Neg("neg", 054, NegCmd);
    OneOperandInstruction Negb("negb", 01054, NegbCmd);

    OneOperandInstruction Swab("swab", 03, SwabCmd);

}
