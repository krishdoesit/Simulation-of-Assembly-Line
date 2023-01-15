//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#include "Utilities.h"
using namespace std;
namespace sdds 
{

    char Utilities::m_delimiter = ' ';

    void sdds::Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t sdds::Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string sdds::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        std::string str1 = "";
        size_t position = next_pos;
        bool find = false;
        if (str.at(next_pos) == m_delimiter) 
        {
            more = false;
            throw std::invalid_argument("Invalid record!");
            return str1;
        }

        while (position < str.size() && !find)
        {
            if (str[position] == m_delimiter)
            {
                find = true;
            }
            else
            {
                position++;
            }
        }


        if (find)
        {
            str1 = str.substr(next_pos, position - next_pos);
            if ((position - next_pos) >= m_widthField)
            {
                m_widthField = position - next_pos;
            }
            next_pos = position + 1;
            more = true;
        }
        else
        {
            more = false;
            str1 = str.substr(next_pos, str.size() - next_pos);
            if ((str.size() - next_pos) >= m_widthField)
            {
                m_widthField = str.length() - next_pos;
            }
        }
        remove_spaces(str1);
        return str1;
    }

    void sdds::Utilities::setDelimiter(char newDelimiter)
    {
        Utilities::m_delimiter = newDelimiter;
    }

    char sdds::Utilities::getDelimiter()
    {
        return Utilities::m_delimiter;
    }


    void Utilities::remove_spaces(std::string& str)
    {
        size_t first = str.find_first_not_of(' ');
        size_t end = str.find_last_not_of(' ');
        str = str.substr(first, end - first + 1);
    }
}