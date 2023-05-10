
////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 09 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>
namespace sdds
{
    class Reservation
    {
    private:
        std::string m_rId{};
        std::string m_name{};
        std::string m_email{};
        std::size_t m_noOfPeople{ 0u };
        std::size_t m_day{ 0u };
        std::size_t m_hour{ 0u };

    public:
        Reservation();
        void update(int day, int time);
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream& ostr, const Reservation& obj);
    };
}
#endif // !SDDS_RESERVATION_H
