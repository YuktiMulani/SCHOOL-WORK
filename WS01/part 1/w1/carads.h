#include <istream>
#ifndef CARADS_H
#define CARADS_H
extern double g_taxrate;
extern double g_discount;

#define BRAND_SIZE 10
#define MODEL_SIZE 15

namespace sdds {
	void listArgs(int argc, char* argv[]);

	class Cars {
		static int counter;

		char brand[BRAND_SIZE];
		char model[MODEL_SIZE];
		int year;
		double price;
		char carStatus;
		char discountStatus;
		bool flag;

	public:
		Cars();
		void read(std::istream& is);
		void display(bool reset);
		char getStatus();
	};
}

#endif