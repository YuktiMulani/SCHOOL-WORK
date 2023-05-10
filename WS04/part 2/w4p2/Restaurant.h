////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 09 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <string>
#include "Reservation.h"
namespace sdds
{
    class Restaurant
    {
        Reservation** m_ptrArr{ nullptr };
        size_t m_elements{ 0u };

    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& obj);
        Restaurant& operator=(const Restaurant& obj);
        Restaurant(Restaurant&& obj) noexcept;
        Restaurant& operator=(Restaurant&& obj) noexcept;
        ~Restaurant();
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& obj);
    };
}
#endif // !SDDS_RESTAURANT_H
