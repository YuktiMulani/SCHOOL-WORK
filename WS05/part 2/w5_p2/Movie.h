#ifndef _MOVIE_H
#define _MOVIE_H

namespace sdds {
    class Movie {
    private:
        std::string m_title = "";
        size_t m_year = 0;
        std::string m_description = "";
    public:
        Movie() {};
        const std::string& title() const;
        Movie(const std::string& strMovie);
        template<typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(this->m_title);
            spellChecker(this->m_description);
        }
        friend std::ostream& operator<<(std::ostream& ostr, Movie M);
    };
    std::ostream& operator<<(std::ostream& ostr, Movie M);
}

#endif
