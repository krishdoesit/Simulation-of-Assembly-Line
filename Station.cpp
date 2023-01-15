//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds 
{
	size_t Station::id_generator = 1;
	size_t Station::m_widthField = 1;

	sdds::Station::Station(std::string record)
	{
		Station::m_widthField = 0;
		id = Station::id_generator++;
		Utilities util;
		size_t next_pos = 0;
		bool more = true;
		std::string token;
		token = util.extractToken(record, next_pos, more);
		m_itemName = token;
		token = util.extractToken(record, next_pos, more);
		m_nsnum = stoi(token);
		token = util.extractToken(record, next_pos, more);
		m_noi = stoi(token);
		if (Station::m_widthField < util.getFieldWidth())
		{
			Station::m_widthField = util.getFieldWidth();
		}
		token = util.extractToken(record, next_pos, more);
		m_description = token;
	}

	const std::string& sdds::Station::getItemName() const
	{
		return m_itemName;
	}

	size_t sdds::Station::getNextSerialNumber()
	{
		return m_nsnum++;
	}

	size_t sdds::Station::getQuantity() const
	{
		return m_noi;
	}

	void sdds::Station::updateQuantity()
	{
		m_noi--;
		if (m_noi < 0) {
			m_noi = 0;
		}
	}

	void sdds::Station::display(std::ostream& os, bool full) const
	{
		if (full)
		{
			//optimized and shorten for easyness and readibility from ms2

			os << setw(3) << setfill('0') << right << id << setfill(' ') << " | " << left << setw(Station::m_widthField) << m_itemName << " | " << setw(6) << setfill('0') << right << m_nsnum << " | " << setfill(' ') << setw(4) << m_noi << " | " << m_description << endl;
		}
		else
		{
			os << setw(3) << setfill('0') << right << id << setfill(' ') << " | " << left << setw(Station::m_widthField) << m_itemName << " | " << setw(6) << setfill('0') << right << m_nsnum << " | " << setfill(' ') << endl;
		}
	}
}