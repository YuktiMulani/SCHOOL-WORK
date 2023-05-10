////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 02 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SDDS_QUEUE_H_
#define SDDS_QUEUE_H_
#include <iostream>
#include "Dictionary.h"

namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Queue
    {
        T m_data[CAPACITY]{};
        size_t m_block{};
        static T m_default;

    public:
        Queue() = default;
        virtual ~Queue() = default;
        virtual bool push(const T &item);
        T pop();
        size_t size() const;
        std::ostream &display(std::ostream &os = std::cout) const;
        T operator[](size_t index) const;
    };

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::m_default{};
    template <>
    Dictionary Queue<Dictionary, 100u>::m_default{"Empty Term", "Empty Substitute"};

    template <typename T, size_t CAPACITY>
    bool Queue<T, CAPACITY>::push(const T &item)
    {

        bool result = false;
        if (m_block < CAPACITY)
        {
            m_data[m_block] = item;
            m_block++;
            result = true;
        }
        return result;
    }

    template <typename T, size_t CAPACITY>
    size_t Queue<T, CAPACITY>::size() const
    {
        return m_block;
    }

    template <typename T, size_t CAPACITY>
    std::ostream &Queue<T, CAPACITY>::display(std::ostream &os) const
    {
        std::cout << "----------------------\n"
                  << "| Dictionary Content |\n----------------------\n";
        for (size_t i = 0; i < m_block; i++)
        {
            os << m_data[i] << std::endl;
        }
        std::cout << "----------------------\n";
        return os;
    }

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::operator[](size_t index) const
    {
        return index < m_block && index >= 0 ? m_data[index] : m_default;
    }

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::pop()
    {
        T result{};
        if (m_block > 0)
        {
            result = m_data[0];
            for (size_t i = 0; i < m_block - 1; i++)
            {
                m_data[i] = m_data[i + 1];
            }
            m_block--;
        }
        return result;
    }
}

#endif