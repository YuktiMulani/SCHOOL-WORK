#ifndef _BOOK_H
#define _BOOK_H

namespace sdds {
    std::string trim(std::string str);
    class Book {
    private:
        std::string m_author = "";
        std::string m_title = "";
        std::string m_country = "";
        size_t m_year = 0;
        double m_price = 0.0;
        std::string m_description = "";
    public:
        Book() {};
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& ostr, Book& B);
        template<typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(this->m_description);
        }
    };
    std::ostream& operator<<(std::ostream& ostr, Book& B);
}

#endif
