#include <iostream>

#include "pdp11_ram.h"

int main()
{

    pdp11::Ram r(50);

    for (std::size_t i = 0; i < r.size(); i++)
        r.set(i, static_cast<pdp11::ubyte>(i));

    r.dump(std::cout, 15);
    0xDEAD;

    return 0;
}

