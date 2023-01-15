//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include "Workstation.h"

using namespace std;

namespace sdds 
{
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	sdds::Workstation::Workstation(std::string& src) : Station(src)
	{
		m_pNextStation = nullptr;
	}


	bool sdds::Workstation::attemptToMoveOrder()
	{
		if (m_orders.size() > 0)
		{
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0)
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					return true;
				}
				else
				{
					if (m_orders.front().isFilled())
					{
						g_completed.push_back(std::move(m_orders.front()));
					}
					else
					{
						g_incomplete.push_back(std::move(m_orders.front()));
					}
					m_orders.pop_front();
					return true;
				}
			}
		}
		return false;
	}


	void sdds::Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}


	void sdds::Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}


	void sdds::Workstation::display(std::ostream& os) const
	{
		os << this->getItemName();
		if (m_pNextStation)
		{
			os << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else
		{
			os << " --> End of Line" << std::endl;
		}
	}

	Workstation* sdds::Workstation::getNextStation() const
	{
		return m_pNextStation;
	}


	Workstation& sdds::Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}
}