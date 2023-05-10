#include <iostream>
#include <string>
#include "Movie.h"
#include "Book.h"

namespace sdds {
    const std::string& Movie::title() const
    {
        return this->m_title;
    }

    Movie::Movie(const std::string& strMovie)
    {
        std::string s = "";
        size_t prev_index = 0, next_index = 0;

        next_index = strMovie.find(",", prev_index);
        s = strMovie.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_title = s;

        prev_index = next_index + 1;
        next_index = strMovie.find(",", prev_index);
        s = strMovie.substr(prev_index, next_index - prev_index);
        s = trim(s);
        this->m_year = (size_t)stoi(s);

        prev_index = next_index + 1;
        s = strMovie.substr(prev_index);
        s = trim(s);
        this->m_description = s;
    }

    std::ostream& operator<<(std::ostream& ostr, Movie M)
    {
        ostr.width(40);
        ostr << M.m_title << " | ";
        ostr.width(4);
        ostr << M.m_year << " | ";
        ostr << M.m_description;
        ostr << std::endl;
        return ostr;
    }
}