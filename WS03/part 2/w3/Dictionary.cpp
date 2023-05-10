////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 02 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////
#include "Dictionary.h"
namespace sdds
{
    std::ostream &operator<<(std::ostream &os, const Dictionary &d)
    {
        os.width(20);
        os.setf(std::ios::right);
        os << d.getTerm() << ": " << d.getDefinition();
        return os;
    }
    bool operator==(const Dictionary &left, const Dictionary &right)
    {
        return left.getTerm() == right.getTerm();
    }
}