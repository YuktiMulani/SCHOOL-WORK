#include <iostream>
#include <string>
#include <fstream>
#include "SpellChecker.h"

namespace sdds {
    SpellChecker::SpellChecker(const char* filename)
    {
        std::ifstream f(filename);
        if (!f) {
            throw "Bad file name!";
            return;
        }
        std::string str = "";
        for (size_t i = 0; i < 6; ++i) {
            std::getline(f, str);
            size_t it = 0;
            while (str[it] != ' ' && str[it] != '\t')
                this->m_badWords[i].push_back(str[it++]);
            while (str[it] == ' ' || str[it] == '\t') ++it;
            while (it != str.length())
                this->m_goodWords[i].push_back(str[it++]);
        }
    }

    void SpellChecker::operator()(std::string& text)
    {
        size_t found = -1;
        for (size_t i = 0; i < 6; ++i) {
            do {
                found = text.find(this->m_badWords[i]);
                if (found != std::string::npos) {
                    text.replace(found, this->m_badWords[i].length(), this->m_goodWords[i]);
                    this->statistics[i] += 1;
                }
            } while (found != std::string::npos);
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const
    {
        std::cout << "Spellchecker Statistics" << std::endl;
        for (int i = 0; i < 6; ++i) {
            out.width(15);
            out.setf(std::ios::right);
            out << this->m_badWords[i];
            out.unsetf(std::ios::right);
            out << ": " << this->statistics[i] << " replacements" << std::endl;
        }
    }

}