//Name: Krish Harshadkumar Patel
//Seneca Email: khpatel28@myseneca.ca
//Student Id: 123898215
//date: 2022/12/03

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#include <fstream>
#include<deque>
#include <algorithm>
#include<vector>
#include "Utilities.h"
#include "LineManager.h"
#include <string>
using namespace std;

namespace sdds {
    sdds::LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        Utilities uts;
        string line, one, two;
        fstream filename(file);
        size_t index = 0;
        bool keepgoing = true;
        while (filename)
        {
            while (getline(filename, line, '\n'))
            {
                char c = Utilities::getDelimiter();
                Utilities::setDelimiter('|');
                one = "";
                two = "";
                index = 0;
                if (line.find_first_of('|') == std::string::npos) {
                    one = line;
                }
                else {
                    one = uts.extractToken(line, index, keepgoing);
                }
                std::for_each(stations.begin(), stations.end(), [&](Workstation* current)
                    {
                        if (one == current->getItemName())
                        {
                            if (keepgoing)
                            {

                                two = uts.extractToken(line, index, keepgoing);

                                if (two != "") {
                                    std::for_each(stations.begin(), stations.end(), [&](Workstation* next)
                                        {
                                            if (two == next->getItemName())
                                            {
                                                current->setNextStation(next);
                                            }
                                        });
                                }
                            }
                            activeLine.push_back(current);
                        }
                    });
                Utilities::setDelimiter(c);
            }
        }
        m_cntCustomerOrder = g_pending.size();
        m_firstStation = activeLine.at(0);
    }

    void LineManager::reorderStations()
    {
        std::deque<Workstation*> temp;
        for (auto& wst : activeLine)
        {
            if (wst->getNextStation() == nullptr) {
                temp.push_back(wst);
            }
        }

        for (auto i = 0u; i < m_cntCustomerOrder; ++i) {
            for (auto& wst : activeLine) {
                if (wst) {
                    if (wst->getNextStation() == temp.front()) {
                        temp.push_front(wst);
                    }
                }
            }
        }

        m_firstStation = temp.front();
        activeLine = temp;
    }

    bool sdds::LineManager::run(std::ostream& os)
    {
        static size_t count = 0;
        size_t prevOrdersFinished = g_completed.size() + g_incomplete.size();
        os << "Line Manager Iteration: " << ++count << endl;
        if (!g_pending.empty())
        {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }
        std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* st)
            {
                st->fill(os);
            });
        std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* st)
            {
                st->attemptToMoveOrder();
            });
        m_cntCustomerOrder -= ((g_completed.size() + g_incomplete.size()) - prevOrdersFinished);
        return m_cntCustomerOrder <= 0;
    }


    void sdds::LineManager::display(std::ostream& os) const
    {
        for (size_t i = 0; i < activeLine.size(); i++)
        {
            activeLine[i]->display(os);
        }
    }
}