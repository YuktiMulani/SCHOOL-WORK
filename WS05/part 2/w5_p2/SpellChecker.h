#ifndef _SPELLCHECKER_H
#define _SPELLCHECKER_H

namespace sdds {
    class SpellChecker {
    private:
        std::string m_badWords[6];
        std::string m_goodWords[6];
        int statistics[6] = { 0 };
    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif
