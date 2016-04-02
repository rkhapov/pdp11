#ifndef ALU_H
#define ALU_H

//ALU for arithmetical, logical and other operation

#include "abstr_cc_alu.h"

#include "pdp11_cpu.h"
#include "pdp11_ram.h"
#include "pdp11_psw.h"
#include "pdp11_types.h"

namespace pdp11
{
    class Alu: public abstr_cc::Alu<pdp11::uword, pdp11::Psw>
    {
    public:

        //function to set Psw according value and new value
        void setPsw(ubyte value, word word16Value, Psw &psw) const;
        void setPsw(uword value, dword dword32Value, Psw &psw) const;

        uword add(uword w1, uword w2, Psw &psw) const;
        uword sub(uword w1, uword w2, Psw &psw) const;

        uword logicalNot(uword w, Psw &psw) const;
        uword logicalOr(uword w1, uword w2, Psw &psw) const;
        uword logicalAnd(uword w1, uword w2, Psw &psw) const;
        uword logicalXor(uword w1, uword w2, Psw &psw) const;

        uword bytesToWord(ubyte low, ubyte high) const;

        //"Parse" instruction for operands
        //Return struct with information about operand: number of register (-1 if operand in memory),
        //adress im memory (-1 of operand in registers), number of changed register and value of change
        //In case of indexing addressing both of registerNumber and memoryAdress != -1, but
        //registerNumber always is 6 (PC)
        struct Operand
        {
            Operand():
                registerNumber(-1),
                memoryAdress(-1),
                value(0)
            {}

            Operand(int rn, int ma, int v):
                registerNumber(rn),
                memoryAdress(ma),
                value(v)
            {}

            int registerNumber;
            int memoryAdress;

            int value;

            //Set operand value with value
            void setByte(Cpu &cpu, Ram &ram, ubyte val);
            void setWord(Cpu &cpu, Ram &ram, uword val);

            uword getWord(Cpu &cpu, Ram &ram, Alu &alu) const;
            ubyte getByte(Cpu &cpu, Ram &ram, Alu &alu) const;

            uword *getWordPointer(Cpu &cpu, Ram &ram) const;
            ubyte *getBytePointer(Cpu &cpu, Ram &ram) const;
        };

        Operand decodeWordOperand(uword code, bool isByteInstruction, const Cpu &cpu, const Ram &ram);
    };
}

#endif // ALU_H
