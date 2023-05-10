
////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 09 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Restaurant.h"
using namespace std;
namespace sdds
{
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
    {
        m_elements = cnt;
        m_ptrArr = new Reservation * [m_elements];
        for (size_t i = 0; i < m_elements; i++)
            m_ptrArr[i] = new Reservation(*reservations[i]);
    }
    Restaurant::Restaurant(const Restaurant& obj)
    {
        m_ptrArr = nullptr;
        *this = obj;
    }
    Restaurant& Restaurant::operator=(const Restaurant& obj)
    {
        if (this != &obj)
        {
            for (size_t i = 0; i < m_elements; i++)
            {
                delete m_ptrArr[i];
            }
            delete[] m_ptrArr;
            m_elements = obj.m_elements;
            if (obj.m_ptrArr != nullptr)
            {
                m_ptrArr = new Reservation * [m_elements];
                for (size_t i = 0; i < m_elements; i++)
                {
                    m_ptrArr[i] = new Reservation(*obj.m_ptrArr[i]);
                }
            }
            else
            {
                m_ptrArr = nullptr;
            }
        }
        return *this;
    }
    Restaurant::Restaurant(Restaurant&& obj) noexcept
    {
        *this = move(obj);
    }
    Restaurant& Restaurant::operator=(Restaurant&& obj) noexcept
    {
        if (this != &obj)
        {
            for (size_t i = 0; i < m_elements; i++)
            {
                delete m_ptrArr[i];
            }
            delete[] m_ptrArr;
            m_ptrArr = obj.m_ptrArr;
            m_elements = obj.m_elements;
            for (size_t i = 0; i < m_elements; i++)
            {
                m_ptrArr[i] = obj.m_ptrArr[i];
            }
            obj.m_ptrArr = nullptr;
            obj.m_elements = 0u;
        }
        return *this;
    }
    size_t Restaurant::size() const
    {
        return m_elements;
    }
    Restaurant::~Restaurant()
    {
        for (size_t i = 0; i < m_elements; i++)
        {
            delete m_ptrArr[i];
        }
        delete[] m_ptrArr;
    }
    std::ostream& operator<<(std::ostream& os, const Restaurant& res)
    {
        static size_t counter = 1;
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << "\nFancy Restaurant (" << counter++ << ")\n";
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << endl;
        if (res.m_elements > 0)
        {
            for (size_t i = 0; i < res.m_elements; i++)
                os << *res.m_ptrArr[i];
        }
        else
        {
            os << "This restaurant is empty!\n";
        }
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << endl;
        return os;
    }
}
