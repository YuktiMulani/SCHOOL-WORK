#define _CRT_SECURE_NO_WARNINGS
#include "carads.h"
#include <iostream>
#include <string>
#include <iomanip>

double g_taxrate;
double g_discount;

namespace sdds {
	int Cars::counter = 1;

	Cars::Cars()
	{
		this->brand[0] = '\0';
		this->model[0] = '\0';
		this->price = -1;
		this->carStatus = '0';
		this->discountStatus = '0';
		this->flag = false;
		this->year = -1;
	}
	void Cars::read(std::istream& is)
	{
		this->brand[0] = '\0';
		this->model[0] = '\0';
		this->price = -1;
		this->carStatus = '0';
		this->discountStatus = '0';
		this->flag = false;
		this->year = -1;

		if (is.good()) {
			is >> this->carStatus;

			if (is.peek() == ',')
			{
				is.get();
			}
			else
			{
				is.setstate(std::ios::failbit);
			}

			is.getline(this->brand, 10, ',');
			is.getline(this->model, 15, ',');
			is >> year;
			is.get();
			is >> price;
			is.get();
			is >> this->discountStatus;
			is.get();
		}

	}
	void Cars::display(bool reset)
	{
		if (reset) {
			counter = 1;
		}

		double taxPrice = (price * g_taxrate) + price;
		std::cout << std::left << std::setw(2) << counter++ << ". ";

		if (this->brand[0] != '\0')
		{//Display Section
			std::cout << std::left << std::setw(10) << this->brand;
			std::cout << "| " << std::left << std::setw(15) << this->model;
			std::cout << "| " << this->year;
			std::cout << " |" << std::right << std::setw(12) << std::setprecision(2) << std::fixed << taxPrice;

			if (this->discountStatus == 'Y')
			{
				double specialPrice = taxPrice - (taxPrice * g_discount);
				std::cout << "|" << std::right << std::setw(12) << std::setprecision(2) << std::fixed << specialPrice;
			}
			else
			{
				std::cout << "|";
			}

		}
		else
		{
			std::cout << "No Order";

		}

		std::cout << std::endl;

	}

	char Cars::getStatus()
	{
		return this->carStatus;
	}

	void listArgs(int argc, char* argv[])
	{
		std::cout << "Command Line:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++) {
			std::cout <<"  "<<i + 1 << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------\n" << std::endl;
	}
}