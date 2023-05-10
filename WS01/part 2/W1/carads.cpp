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
//~asam.gulaid1/submit 345_w1_p2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "carads.h"

double g_taxrate, g_discount;

namespace sdds {
	//static int counter = 0;

	void listArgs(int argc, char* argv[])
	{
		std::cout << "Command Line:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++)
		{
			std::cout << "  " << i + 1 << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------" << std::endl << std::endl;

		//Command Line :
		//--------------------------
		//1: < first argument>
		//2: < second argument>
		//3: < third argument>
		//4: ...
	}

	Cars::Cars() {} //safe empty state

	//Rule of three
	Cars::Cars(const Cars& car) 
	{
		*this = car;
	}

	Cars::~Cars()
	{
		delete[] brand;
	}

	Cars& Cars::operator=(const Cars& car)
	{
		if (this != &car && car.brand != nullptr) //
		{
			delete[] brand;
			brand = new char[strlen(car.brand) + 1];

			strcpy(brand, car.brand);
			strcpy(model, car.model);
			manufactureYear = car.manufactureYear;
			price = car.price;
			status = car.status;
			promotion = car.promotion;

		}
		return *this;
	}

	Cars::operator bool() const
	{
		return status == 'N'; // N is new.
	}

	void Cars::read(std::istream& is)
	{
		std::string carBrand;
		char discount = 'k'; 

		if (is) {
			is >> status; // N(new car) or U(used car)
			is.ignore(); // ,
			std::getline(is, carBrand, ',');
			
			//brand
			if (carBrand.length() > 0) {
				delete[] brand;
				brand = new char[carBrand.length() + 1];
				strcpy(brand, carBrand.c_str());
			}

			//model
			is.get(model, 16, ','); //15+1
			is.ignore();

			//year
			is >> manufactureYear;
			is.ignore();

			//price
			is >> price;
			is.ignore();

			//discout - promotion Y or N
			is >> discount;

			promotion = discount == 'Y' ? true : false;
			is.ignore();
		}
	}

	void Cars::display(bool reset) const
	{
		static int counter = 0;
		if (reset) {
			counter = 0;
		}
		counter++;
		double taxed_price = price + (price * g_taxrate);
		double discounted_price = taxed_price - (taxed_price * g_discount);

		if (strlen(brand) > 0) {
			//brand - 10, model 15, year 4 field number,price with Tax 12, 2 decimal
			std::cout.width(2);
			std::cout << std::left << counter << ". ";
			std::cout.width(10);
			std::cout << std::left << brand << "| ";
			std::cout.width(15);
			std::cout << std::left << model << "| ";
			std::cout << manufactureYear << " |";
			std::cout.width(12);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << std::right << taxed_price << "|";

			//special price 12 - taxed price
			if (promotion) {
				std::cout.width(12);
				std::cout << std::right << discounted_price << std::endl;
			}
			else {
				std::cout << std::endl; // print nothing
			}
		}
		else {
			std::cout << counter << ". No Car";
		}


	}

	char Cars::getStatus() const
	{
		return status;
	}

	//extraction operator
	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}

}