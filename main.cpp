#include <iostream>

#include "pdp11_system_unit.h"

int main()
{
    pdp11::SystemUnit su(20);

    su.getRam().set(0, 0);
    su.getRam().set(1, 0);

    std::cout << su.executeNextInstruction() << std::endl;

    su.dump(std::cout);

    return 0;
}
