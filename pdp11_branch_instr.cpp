#include "pdp11_branch_instr.h"

namespace pdp11
{
    int BrCmd(uword instructionCode, Cpu &cpu,
              Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        return 0;
    }

    int BrneCmd(uword instructionCode, Cpu &cpu,
                Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getZero() == false)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }
        return 0;
    }

    int BeqCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getZero() == true)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }
        return 0;
    }

    int BplCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getNegative() == false)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }

        return 0;
    }

    int BmiCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getNegative() == true)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }

        return 0;
    }

    int BvcCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getOverflow() == true)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }

        return 0;
    }

    int BvsCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getOverflow() == false)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }

        return 0;
    }

    int BccCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getCarry() == true)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }

        return 0;
    }

    int BcsCmd(uword instructionCode, Cpu &cpu,
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        if (cpu.getStatusWord().getCarry() == false)
        {
            cpu.setRegister(7, cpu.getRegister(7) + 2 * (instructionCode & 0xFF));
        }

        return 0;
    }

    BranchInstruction Br("br", 1, BrCmd);
    BranchInstruction Brne("brne", 2, BrneCmd);
    BranchInstruction Beq("beq", 3, BeqCmd);
    BranchInstruction Bpl("bpl", 0x80, BplCmd);
    BranchInstruction Bmi("bmi", 0x81, BmiCmd);
    BranchInstruction Bvc("bvc", 0x84, BvcCmd);
    BranchInstruction Bvs("bvs", 0x85, BvsCmd);
    BranchInstruction Bcc("bcc", 0x86, BccCmd);
    BranchInstruction Bcs("bcs", 0x87, BcsCmd);
}
