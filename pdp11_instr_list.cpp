#include "pdp11_instr_list.h"

#include "pdp11_zero_op_table.h"
#include "pdp11_one_op_table.h"
#include "pdp11_branch_instr.h"
#include "pdp11_psw_instr.h"
#include "pdp11_two_op_instr.h"

pdp11::InstructionList::InstructionList()
{
    _instructions.push_back(&Halt);
    _instructions.push_back(&Nop);

    _instructions.push_back(&Clc);
    _instructions.push_back(&Clv);
    _instructions.push_back(&Clz);
    _instructions.push_back(&Cln);
    _instructions.push_back(&Ccc);

    _instructions.push_back(&Sec);
    _instructions.push_back(&Sev);
    _instructions.push_back(&Sez);
    _instructions.push_back(&Sen);
    _instructions.push_back(&Scc);

    _instructions.push_back(&Clr);
    _instructions.push_back(&Clrb);
    _instructions.push_back(&Inc);
    _instructions.push_back(&Dec);
    _instructions.push_back(&Decb);
    _instructions.push_back(&Adc);
    _instructions.push_back(&Adcb);
    _instructions.push_back(&Sbc);
    _instructions.push_back(&Sbcb);
    _instructions.push_back(&Tst);
    _instructions.push_back(&Tstb);
    _instructions.push_back(&Neg);
    _instructions.push_back(&Negb);
    _instructions.push_back(&Swab);

    _instructions.push_back(&Br);
    _instructions.push_back(&Brne);
    _instructions.push_back(&Beq);
    _instructions.push_back(&Bpl);
    _instructions.push_back(&Bmi);
    _instructions.push_back(&Bvc);
    _instructions.push_back(&Bvs);
    _instructions.push_back(&Bcc);
    _instructions.push_back(&Bcs);

    _instructions.push_back(&Mov);
    _instructions.push_back(&Movb);
    _instructions.push_back(&Add);
    _instructions.push_back(&Sub);
    _instructions.push_back(&Cmp);
    _instructions.push_back(&Cmpb);
}


pdp11::Instruction* pdp11::InstructionList::find(uword instructionCode)
{
    //Find instruction which are matches with instructionCode
    for (std::size_t i = 0; i < _instructions.size(); i++)
    {
        if (_instructions[i]->checkCode(instructionCode) == true)
        {
            return _instructions[i];
        }
    }

    return nullptr;
}

pdp11::Instruction* pdp11::InstructionList::find(const std::string &mnemonic)
{
    //find instruction which are matches with mnemonic
    for (std::size_t i = 0; i < _instructions.size(); i++)
    {
        if (_instructions[i]->getMnemonic() == mnemonic)
        {
            return _instructions[i];
        }
    }

    return nullptr;
}
