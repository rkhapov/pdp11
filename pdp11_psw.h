#ifndef PSW_H
#define PSW_H

//PDP-11 processor status word

#include "abstr_cc_status_word.h"

#include "pdp11_types.h"

namespace pdp11
{
    class Psw: public abstr_cc::StatusWord<pdp11::uword>
    {
    public:
        Psw():
            StatusWord<pdp11::uword>(0)
        {}

        //There are 5 flags: C, V (overflow), Z, N, and Halt-flag
        //Carry - 0 bit
        //Overflow - 1 bit
        //Zero - 2 bit
        //Negative - 3 bit
        void setCarry(bool val) { StatusWord<pdp11::uword>::set(0, val); }
        void setOverflow(bool val) { StatusWord<pdp11::uword>::set(1, val); }
        void setZero(bool val) { StatusWord<pdp11::uword>::set(2, val); }
        void setNegative(bool val) { StatusWord<pdp11::uword>::set(3, val); }
    };
}

#endif // PSW_H
