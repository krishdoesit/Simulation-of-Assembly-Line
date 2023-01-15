//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include<deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds 
{

	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station 
	{
	private:
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation = nullptr;

	public:
		Workstation(std::string& src);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		Workstation(Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

	};
}



#endif // !SDDS_WORKSTATION_H


