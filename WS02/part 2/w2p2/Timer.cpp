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
#include <chrono>

#include "Timer.h"

using namespace std;

namespace sdds {

    void Timer::start() {
        startTime = chrono::steady_clock::now();
    }

    long long Timer::stop() {
        long long elapsed;
        endTime = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
        return elapsed;
    }

}