#ifndef ABSTR_CC_CPU_H
#define ABSTR_CC_CPU_H

/*
 * CPU contains registers and status word
 * both of this user can manipulate
*/

#include <stdexcept>

#include "abstr_cc_status_word.h"

namespace abstr_cc
{
    template <class word_t, class StatusWord_t, int regNumber>
    class Cpu
    {
    public:
        virtual ~Cpu() {}

        void setRegister(int registerNumber, const word_t &value)
        {
            if (registerNumber >= regNumber || registerNumber < 0)
                throw std::out_of_range("Cpu register out of range");

            _registers[registerNumber] = value;
        }

        const word_t &getRegister(int registerNumber) const
        {
            if (registerNumber < 0 || registerNumber >= regNumber)
                throw std::out_of_range("Cpu register out of range");

            return _registers[registerNumber];
        }


        word_t &getRegister(int registerNumber)
        {
            if (registerNumber < 0 || registerNumber >= regNumber)
                throw std::out_of_range("Cpu register out of range");

            return _registers[registerNumber];
        }

        int getRegisterNumber() const { return regNumber; }

        const StatusWord_t &getStatusWord() const { return _flags; }
        StatusWord_t &getStatusWord() { return _flags; }

    private:
        //Registers
        word_t _registers[regNumber];

        //Flag register
        StatusWord_t _flags;
    };
}

#endif // ABSTR_CC_CPU_H

