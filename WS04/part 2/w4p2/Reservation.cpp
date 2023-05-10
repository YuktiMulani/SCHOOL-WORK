////////////////////////////////////////////////////////////////////////////////////////////
//Name - Yukti Manoj Mulani
//Email - Ymulani@myseneca.ca
//Student ID - 156809212
//Date - 09 / 10 / 2022 (dd / mm / yyyy)
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Reservation.h"
using namespace std;
namespace sdds
{
    string tokenExtractSpaceRemover(string& str, char terminator)
    {
        int termIdx = str.find(terminator);
        string res = str.substr(0, termIdx);
        str.erase(0, termIdx + 1);
        res.erase(0, res.find_first_not_of(' '));
        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }
    Reservation::Reservation() {}
    void Reservation::update(int day, int time)
    {
        m_day = day;
        m_hour = time;
    }
    Reservation::Reservation(const string& res)
    {
        string record = res;
        m_rId = tokenExtractSpaceRemover(record, ':');
        m_name = tokenExtractSpaceRemover(record, ',');
        m_email = tokenExtractSpaceRemover(record, ',');
        m_noOfPeople = stoi(tokenExtractSpaceRemover(record, ','));
        m_day = stoi(tokenExtractSpaceRemover(record, ','));
        m_hour = stoi(tokenExtractSpaceRemover(record, ','));
    }
    ostream& operator<<(ostream& os, const Reservation& src)
    {
        os << "Reservation ";
        os.width(10);
        os << right << src.m_rId << ": ";
        os.width(20);
        os << right << src.m_name << "  ";
        os.width(20);
        os << left << ("<" + src.m_email + ">") << "    ";
        if (src.m_hour >= 6 && src.m_hour <= 9)
        {
            os << "Breakfast";
        }
        else if (src.m_hour >= 11 && src.m_hour <= 15)
        {
            os << "Lunch";
        }
        else if (src.m_hour >= 17 && src.m_hour <= 21)
        {
            os << "Dinner";
        }
        else
        {
            os << "Drinks";
        }
        os << " on day " << src.m_day;
        os << " @ " << src.m_hour << ":00";
        os << " for " << src.m_noOfPeople;
        if (src.m_noOfPeople == 1)
        {
            os << " person";
        }
        else
        {
            os << " people";
        }
        os << "." << endl;
        return os;
    }
}
