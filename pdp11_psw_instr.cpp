#include "pdp11_psw_instr.h"

namespace pdp11
{
    int ClcCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setCarry(0);
        return 0;
    }

    int ClvCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setOverflow(0);
        return 0;
    }

    int ClzCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setZero(0);
        return 0;
    }

    int ClnCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setNegative(0);
        return 0;
    }

    int CccCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setCarry(0);
        cpu.getStatusWord().setNegative(0);
        cpu.getStatusWord().setOverflow(0);
        cpu.getStatusWord().setZero(0);
        return 0;
    }

    int SecCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setCarry(1);
        return 0;
    }

    int SevCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setOverflow(1);
        return 0;
    }

    int SezCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setZero(1);
        return 0;
    }

    int SenCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setNegative(1);
        return 0;
    }

    int SccCmd(uword instructionCode __attribute__((unused)), Cpu &cpu __attribute__((unused)),
               Ram &ram __attribute__((unused)), Alu &alu __attribute__((unused)))
    {
        cpu.getStatusWord().setCarry(1);
        cpu.getStatusWord().setNegative(1);
        cpu.getStatusWord().setOverflow(1);
        cpu.getStatusWord().setZero(1);
        return 0;
    }

    ZeroOperandInstruction Clc("clc", 0241, ClcCmd);
    ZeroOperandInstruction Clv("clv", 0242, ClvCmd);
    ZeroOperandInstruction Clz("clz", 0244, ClzCmd);
    ZeroOperandInstruction Cln("cln", 0250, ClnCmd);
    ZeroOperandInstruction Ccc("ccc", 0257, CccCmd);

    ZeroOperandInstruction Sec("sec", 0261, SecCmd);
    ZeroOperandInstruction Sev("sev", 0262, SevCmd);
    ZeroOperandInstruction Sez("sez", 0264, SezCmd);
    ZeroOperandInstruction Sen("sen", 0270, SenCmd);
    ZeroOperandInstruction Scc("scc", 0277, SccCmd);
}
