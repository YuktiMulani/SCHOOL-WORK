/*
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------//
Name		: Yukti Manoj Mulani
Seneca Email: ymulani@myseneca.ca
Student ID	: 156809212
Date		: September 25, 2022
//-----------------------------------------------------------//
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "TennisLog.h"

using namespace std;

namespace sdds {

    TennisMatch::TennisMatch() {
        t_Id = "";
        t_name = "";
        match_Id = 0;
        m_winner = "";
        m_loser = "";
    }

    TennisMatch::TennisMatch(string tId, string tName, unsigned int matchId, string winner, string loser) {
        t_Id = tId;
        t_name = tName;
        match_Id = matchId;
        m_winner = winner;
        m_loser = loser;
    }

    std::ostream& operator<<(std::ostream& os, const TennisMatch& match) {
        if (match.t_Id != "" && match.t_name != "" && match.match_Id != 0) {
            cout << setw(20) << right << setfill('.') << "Tourney ID" << " : " << setw(30) << left << match.t_Id << endl;
            cout << setw(20) << right << setfill('.') << "Match ID" << " : " << setw(30) << left << match.match_Id << endl;
            cout << setw(20) << right << setfill('.') << "Tourney" << " : " << setw(30) << left << match.t_name << endl;
            cout << setw(20) << right << setfill('.') << "Winner" << " : " << setw(30) << left << match.m_winner << endl;
            cout << setw(20) << right << setfill('.') << "Loser" << " : " << setw(30) << left << match.m_loser << endl;
        }
        else {
            cout << "Empty Match";
        }
        return os;
    }


    TennisLog::TennisLog() {
        matches = nullptr;
        size = 0;
    }


    TennisLog::TennisLog(const char* filename) {
        unsigned int count = 0;
        string line;
        ifstream f(filename);
        getline(f, line);
        if (f.is_open()) {
            while (getline(f, line)) {
                size++;
            }
            f.close();
        }
        matches = new TennisMatch[size];
        f.open(filename);
        getline(f, line);
        if (f.is_open()) {
            while (!f.eof()) {
                getline(f, matches[count].t_Id, ',');
                getline(f, matches[count].t_name, ',');
                f >> matches[count].match_Id;
                f.ignore();
                getline(f, matches[count].m_winner, ',');
                getline(f, matches[count].m_loser);
                if (!f.fail()) {
                    count++;
                }
                if (count == size) {
                    f.setstate(ios_base::eofbit);
                }
            }
        }
        f.close();
    }

    // Rule of 5 

    TennisLog::TennisLog(const TennisLog& source) {
        matches = nullptr;
        *this = source;
    }

    TennisLog& TennisLog::operator=(const TennisLog& source) {
        if (this != &source) {
            delete[] matches;
            size = source.size;
            if (source.matches != nullptr) {
                matches = new TennisMatch[size];
                for (auto i = 0u; i < size; i++) {
                    matches[i].t_Id = source.matches[i].t_Id;
                    matches[i].t_name = source.matches[i].t_name;
                    matches[i].match_Id = source.matches[i].match_Id;
                    matches[i].m_winner = source.matches[i].m_winner;
                    matches[i].m_loser = source.matches[i].m_loser;
                }
            }
            else {
                matches = nullptr;
            }
        }
        return *this;
    }


    TennisLog::TennisLog(TennisLog&& source) noexcept {
        matches = nullptr;
        *this = std::move(source);
    }


    TennisLog& TennisLog::operator=(TennisLog&& source) noexcept {
        if (this != &source) {
            delete[] matches;
            size = source.size;
            matches = source.matches;
            source.matches = nullptr;
            source.size = 0;
        }

        return *this;
    }

    TennisLog::~TennisLog() {
        delete[]matches;
        matches = nullptr;
    }

    void TennisLog::addMatch(TennisMatch& newMatch) {
        TennisLog tempLog;
        tempLog.matches = new TennisMatch[size + 1];
        tempLog.size = size + 1;
        if (matches != nullptr) {
            for (auto i = 0u; i < size; i++) {
                tempLog.matches[i] = matches[i];
            }
        }
        tempLog.matches[size] = newMatch;
        *this = move(tempLog);
    }

    TennisLog TennisLog::findMatches(const string pName) {
        TennisLog result;
        for (auto i = 0u; i < size; i++) {
            if (pName == matches[i].m_winner || pName == matches[i].m_loser) {
                result.addMatch(matches[i]);
            }
        }
        return result;
    }

    TennisMatch TennisLog::operator[](size_t index) const {
        TennisMatch result;
        if (size > index && matches != nullptr) {
            result = matches[index];
        }
        return result;
    }

    TennisLog::operator size_t() const {
        return size;
    }


}