#include <iostream>

#include "pdp11_alu.h"

int main()
{

    pdp11::uword v = 0xAABB;

    v = (v >> 8) | (v << 8);

    std::cout << std::hex << v << std::endl;
    std::cout << int((pdp11::byte)v) << std::endl;

    return 0;
}
