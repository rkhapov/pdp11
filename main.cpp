#include <iostream>

#include "pdp11_cpu.h"
#include "pdp11_alu.h"
#include "pdp11_ram.h"

#include <limits>

int main()
{

    std::cout << std::numeric_limits<pdp11::word>::min() << std::endl;

    return 0;
}
