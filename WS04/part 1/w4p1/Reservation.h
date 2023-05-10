#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
namespace sdds {
	const std::string WHITESPACE = "\n\r\t\f\v";
	class Reservation {
	private:
		char reservation_id[7]={};
		std::string name;
		std::string econfirm;
		int population;
		int day;
		int hour;
	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator <<(std::ostream& os, const Reservation& res);
	};
}
#endif
