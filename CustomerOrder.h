//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include<iostream>
#include "Utilities.h"
#include "Station.h"
#include <string>

namespace sdds 
{

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder 
	{
	private:
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};
		static size_t m_widthField;
	public:
		CustomerOrder() = default;//default constructor
		CustomerOrder(std::string& str);//constructor to extarct tokens from string and current instance
		CustomerOrder(const CustomerOrder& rOperand); 
		CustomerOrder(CustomerOrder&&) noexcept; // move constructor
		CustomerOrder& operator=(CustomerOrder&& rOperand) noexcept; // move assignment operator
		~CustomerOrder();//destructor
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
		bool isFilled() const;

	};
}




#endif // !SDDS_CUSTOMERORDER_H

