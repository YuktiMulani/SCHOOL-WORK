
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

#ifndef TENNISLOG_H
#define TENNISLOG_H

using namespace std;

namespace sdds {

    struct TennisMatch {

        string t_Id = "";
        string t_name = "";
        unsigned int match_Id = 0;
        string m_winner = "";
        string m_loser = "";
        TennisMatch();
        TennisMatch(string tId, string tName, unsigned int matchId, string winner, string loser);
    };

    std::ostream& operator <<(std::ostream& os, const TennisMatch& match);

    class TennisLog {
        TennisMatch* matches = nullptr;
        unsigned int size = 0;

    public:
        TennisLog();
        TennisLog(const char* filename);
        //Rule of Five
        TennisLog(const TennisLog& source);
        TennisLog& operator=(const TennisLog& source);
        TennisLog(TennisLog&& source) noexcept;
        TennisLog& operator=(TennisLog&& source) noexcept;
        ~TennisLog();
        void addMatch(TennisMatch& newMatch);
        TennisLog findMatches(const string pName);
        TennisMatch operator[](size_t) const;
        operator size_t() const;
    };

}

#endif // TENNISLOG_H