#include <iostream>
#include <string>
#include "Book.h"

namespace sdds {
    std::string trim(std::string str)
    {
        size_t i = str.find_first_not_of(" ");
        str = str.substr(i);

        i = str.find_last_not_of(" ");
        str = str.substr(0, i + 1);
        return str;
    }

    const std::string& Book::title() const
    {
        return this->m_title;
    }

    const std::string& Book::country() const
    {
        return this->m_country;
    }

    const size_t& Book::year() const
    {
        return this->m_year;
    }

    double& Book::price()
    {
        return (this->m_price);
    }

    Book::Book(const std::string& strBook)
    {
        std::string s = "";
        size_t prev_index = 0, next_index = 0;

        next_index = strBook.find(",", prev_index);
        s = strBook.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_author = s;

        prev_index = next_index + 1;
        next_index = strBook.find(",", prev_index);
        s = strBook.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_title = s;

        prev_index = next_index + 1;
        next_index = strBook.find(",", prev_index);
        s = strBook.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_country = s;

        prev_index = next_index + 1;
        next_index = strBook.find(",", prev_index);
        s = strBook.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_price = stod(s);

        prev_index = next_index + 1;
        next_index = strBook.find(",", prev_index);
        s = strBook.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_year = (size_t)stoi(s);

        prev_index = next_index + 1;
        s = strBook.substr(prev_index);
        s = trim(s);
        this->m_description = s;
    }

    std::ostream& operator<<(std::ostream& ostr, Book& B)
    {
        ostr.width(20);
        ostr << B.m_author << " | ";
        ostr.width(22);
        ostr << B.m_title << " | ";
        ostr.width(5);
        ostr << B.m_country << " | ";
        ostr.width(4);
        ostr << B.m_year << " | ";
        ostr.width(6);
        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr << B.m_price << " | ";
        ostr << B.m_description << std::endl;
        return ostr;
    }

}