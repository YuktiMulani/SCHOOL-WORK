#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include <stdexcept>
#include "Reservation.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {
	Reservation::Reservation() {
		reservation_id[7] = {};
		name = '\0';
		econfirm = '\0';
		population = 0;
		day = 0;
		hour = 0;
	}
	void Reservation::update(int d, int time) {
		day = d;
		hour = time;
	}
	Reservation::Reservation(const std::string& res) {
		std::string WHITESPACES = "\t,\n,\r,\f,\v";
		std::string s = ":";
		std::string e = std::to_string(res[1]);
		econfirm = e;//only remove trailing spaces you can use find() and erase()
		for (int i = 0; i < sizeof(econfirm) + 1; i++) {
			for (int j = 0; j < sizeof(WHITESPACES) + 1; i++) {
				if (WHITESPACES[j] = econfirm[i]) {
					econfirm.erase(i);
				}
			}
		}
		std::string d = std::to_string(res[3]);
		day = stoi(d);
		std::string h = std::to_string(res[4]);
		hour = stoi(h);
		std::string p = std::to_string(res[2]);
		population = stoi(p);
		std::string n = std::to_string(res[0]);
		name = n;// remove trailing spaces you can use find() and erase()
		for (int x = 0; x < sizeof(name) + 1; x++) {
			for (int y = 0; y < sizeof(WHITESPACES) + 1; y++) {
				if (name[x] =':') {
					name.erase(0, x);//eliminates the id part from the first position of the string
				}
				if (WHITESPACES[y] = name[x]) {
					name.erase(x);// removes whitespaces
				}
			}
		}
		size_t found = n.find(s);//finds till where is the id in the first pos of the string res
		std::string id = n.erase(0, found - 1);// assigns the erased part of the string n to id
		for (int x = 0; x < sizeof(id) + 1; x++) {
			for (int y = 0; y < sizeof(WHITESPACES) + 1; y++) {
				if (WHITESPACES[y] = id[x]) {
					id.erase(x);// removes whitespaces
				}
			}
		}
		strcpy(reservation_id,id.c_str());

	}
	std::ostream& operator <<(std::ostream& os,const Reservation& res) {
		if (res.hour >= 6 || res.hour <= 9) {
			if (res.population == 1) {
				os << "Reservation" <<std::setw(10)<<std::right << res.reservation_id <<std::setw(20)<<std::right << res.name << std::setw(20) <<std::left<<"<" << std::setw(20) << std::left << res.econfirm <<std:: setw(20) << std::left <<">" << "Breakfast on day" << res.day << "@" << res.hour << ":00 for" << res.population << "person." << std::endl;
			}
			if (res.population > 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Breakfast on day" << res.day << "@" << res.hour << ":00 for" << res.population << "people." << std::endl;


			}
		}
		if (res.hour >= 11 || res.hour <= 15) {
			if (res.population == 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Lunch on day" << res.day << "@" << res.hour << ":00 for" << res.population << "person." << std::endl;
			}
			if (res.population > 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Lunch on day" << res.day << "@" << res.hour << ":00 for" << res.population << "people." << std::endl;


			}
		}
		if (res.hour >= 17 || res.hour <= 21) {
			if (res.population == 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Dinner on day" << res.day << "@" << res.hour << ":00 for" << res.population << "person." << std::endl;
			}
			if (res.population > 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Dinner on day" << res.day << "@" << res.hour << ":00 for" << res.population << "people." << std::endl;


			}
		}
		else {
			if (res.population == 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Drinks on day" << res.day << "@" << res.hour << ":00 for" << res.population << "person." << std::endl;
			}
			if (res.population > 1) {
				os << "Reservation" << std::setw(10) << std::right << res.reservation_id << std::setw(20) << std::right << res.name << std::setw(20) << std::left << "<" << std::setw(20) << std::left << res.econfirm << std::setw(20) << std::left << ">" << "Drinks on day" << res.day << "@" << res.hour << ":00 for" << res.population << "people." << std::endl;


			}
		}
	}

}