//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds 
{
	class Utilities 
	{
		size_t m_widthField{ 1 }; 
		static char m_delimiter;  //static class variable 
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const; 
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more); 
		static void setDelimiter(char newDelimiter);
		static char getDelimiter(); 
		void remove_spaces(std::string& str);
	};
}
#endif 
