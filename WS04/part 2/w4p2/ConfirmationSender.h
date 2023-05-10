////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 09 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SDDS_CONFIRMATION_SENDER_H
#define SDDS_CONFIRMATION_SENDER_H
#include "Reservation.h"
namespace sdds
{
    class ConfirmationSender
    {
        const Reservation **m_pReservations{nullptr};
        size_t m_elements{0u};

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender &obj);
        ConfirmationSender &operator=(const ConfirmationSender &obj);
        ConfirmationSender(ConfirmationSender &&obj);
        ConfirmationSender &operator=(ConfirmationSender &&obj);
        ConfirmationSender &operator+=(const Reservation &obj);
        ConfirmationSender &operator-=(const Reservation &obj);
        ~ConfirmationSender();
        friend std::ostream &operator<<(std::ostream &ostr, const ConfirmationSender &obj);
    };
}
#endif // !SDDS_CONFIRMATION_SENDER_H
