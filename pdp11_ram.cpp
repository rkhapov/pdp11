//Dump realization only. Nothing intresting

#include <iomanip>

#include "pdp11_ram.h"

void pdp11::Ram::dump(std::ostream &stream, int ncolomns, int numwidth) const
{
    stream << std::setw(numwidth) << " " << "|";
    for (int i = 0; i < ncolomns; i++)
        stream << std::setw(numwidth) << std::left << std::hex << std::uppercase << i;
    stream << "\n";

    stream << std::setfill('-') << std::setw(numwidth) << "" << "+";
    stream << std::setw(numwidth * ncolomns - 1) << "" << "\n";
    stream << std::setfill(' ');

    for (std::size_t i = 0; i < size(); i += ncolomns)
    {
        stream << std::setw(numwidth) << std::left << std::hex << std::uppercase << i << "|";
        for (std::size_t j = 0; j + i < size() && static_cast<int>(j) < ncolomns; j++)
        {
            stream << std::setw(numwidth) << std::left << std::hex << std::uppercase << static_cast<int>(get(i + j));
        }
        stream << "\n";
    }
    stream << std::endl;
}

