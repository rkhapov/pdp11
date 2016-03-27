#ifndef CPU_H
#define CPU_H

#include "abstr_cc_cpu.h"

#include "pdp11_psw.h"
#include "pdp11_types.h"

namespace pdp11
{
    //PDP-11 CPU is so simple, therefore there are nothing intresting.
    //Just inheritance from abstr_cc::Cpu
    class Cpu: public abstr_cc::Cpu<uword, Psw, 8>
    {
    //Empty
    };
}

#endif // CPU_H
