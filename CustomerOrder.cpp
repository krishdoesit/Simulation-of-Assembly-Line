//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	sdds::CustomerOrder::CustomerOrder(std::string& src)
	{
		Utilities ut;
		std::string str{};
		bool extra = false;
		size_t nextpos{};

		m_name = ut.extractToken(src, nextpos, extra);
		m_product = ut.extractToken(src, nextpos, extra);
		std::vector<Item> items;
		while (extra) {
			str = ut.extractToken(src, nextpos, extra);
			if (str.empty())
				break;
			items.push_back(Item(str));
		}
		if (items.size() > 0) {
			m_lstItem = new Item * [items.size()];
			for (size_t i = 0; i < items.size(); i++) {
				m_lstItem[i] = new Item(items[i]);
			}
			m_cntItem = items.size();
		}
		if (m_widthField < ut.getFieldWidth()) {
			m_widthField = ut.getFieldWidth();
		}
	}

	sdds::CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "copy constructor is not possible here";
	}

	sdds::CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& sdds::CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src) {
			m_name = src.m_name;
			m_product = src.m_product;
			if (m_cntItem > 0) {
				for (size_t i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}
			
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;   
			//emptying
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}


	sdds::CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];  // deleting elements of array
		}
		delete[] m_lstItem;
	}


	bool sdds::CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool keepgoing = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false && m_lstItem[i]->m_itemName == itemName) {
				keepgoing = false;
				break;
			}
		}
		return keepgoing;
	}

	bool sdds::CustomerOrder::isOrderFilled() const
	{
		bool keepgoing = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				keepgoing = false;
				break;
			}
		}
		return keepgoing;
	}

	void sdds::CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (m_lstItem[i]->m_isFilled == false && station.getQuantity() >= 1) {
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [";
					os << m_lstItem[i]->m_itemName << "]" << endl;
					break;
				}
				else if (m_lstItem[i]->m_isFilled == false) {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
				}
			}
		}
	}


	void sdds::CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << '[' << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber;
			os << ']' << setfill(' ') << " ";
			os << setw(m_widthField) << left << m_lstItem[i]->m_itemName;
			if (m_lstItem[i]->m_isFilled)
			{
				os << " - FILLED";
			}
			else
			{
				os << " - TO BE FILLED";
			}
			os << '\n';
		}
	}


	bool CustomerOrder::isFilled() const
	{
		bool check = true;

		for (size_t i = 0u; i < m_cntItem && check == true; i++)
		{
			if (m_lstItem[i]->m_isFilled)
			{

			}
			else
			{
				check = false;
			}
		}
		return check;
	}
}