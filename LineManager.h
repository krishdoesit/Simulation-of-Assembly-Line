//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H
#include <deque>
#include <vector>
#include "Workstation.h"

namespace sdds
{
    class LineManager
    {
    private:
        std::deque<Workstation*> activeLine;
        size_t m_cntCustomerOrder = 0;
        Workstation* m_firstStation = nullptr;

    public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif
