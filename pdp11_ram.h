#ifndef RAM_H
#define RAM_H

//classic PDP-11 ram
//dump is addeded to the abstract Ram

#include <iostream>

#include "abstr_cc_memory.h"

#include "pdp11_types.h"

namespace pdp11
{
    class Ram: public abstr_cc::Ram<ubyte>
    {
    public:
        Ram(std::size_t size):
            abstr_cc::Ram<ubyte>(size)
        {}

        //stream - out stream to dump
        //numwidth - character to single number
        //ncolomns - number of colomns (numbers pers line)
        void dump(std::ostream &stream, int ncolomns = 10, int numwidth = 4) const;
    };
}

#endif // RAM_H
