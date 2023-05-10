/*
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------//
Name		: Haneul Roh
Seneca Email: hroh8@myseneca.ca
Student ID	: 131229213
Date		: September 18, 2022
//-----------------------------------------------------------//
*/


#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include <iostream>

#define MODEL_SIZE 15
//defines the current tax rate and the special promotion discount
//global variables
extern double g_taxrate, g_discount;

namespace sdds {
	void listArgs(int argc, char* argv[]); //same as main function types
	class Cars {
		char* brand{}; //any length in part2
		char model[MODEL_SIZE+1]{}; //null-terminated string of up to 15 characters
		int manufactureYear{};
		double price{};
		char status{};
		bool promotion{};
	public:
		//Rule of 3 here
		Cars();
		Cars(const Cars&);
		Cars& operator=(const Cars&); //copy assignment
		~Cars();
		operator bool() const;
		void read(std::istream& is);
		void display(bool reset) const;
		char getStatus() const;

	};
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);

}


#endif