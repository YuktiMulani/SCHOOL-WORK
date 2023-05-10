
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
#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

using namespace std;

namespace sdds {
    class Timer {
        std::chrono::time_point<std::chrono::steady_clock> startTime;
        std::chrono::time_point<std::chrono::steady_clock> endTime;
    public:
        void start();
        long long stop();
    };
}

#endif // TIMER_H
