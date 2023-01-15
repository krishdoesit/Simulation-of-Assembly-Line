//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds {
	class Station {
		size_t id{};
		std::string m_itemName{};
		std::string m_description{};
		size_t m_nsnum{};
		size_t m_noi{};
		//class variable static
		static size_t m_widthField;
		static size_t id_generator;

	public:

		Station(std::string); 
		const std::string& getItemName() const;
		size_t getNextSerialNumber(); 
		size_t getQuantity() const; 
		void updateQuantity(); 
		void display(std::ostream& os, bool full) const; 
	};
}

#endif // !SDDS_STATION_H


