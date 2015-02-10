//Created By Casey Schurman
//Date: 2/7/2015
//Defines an ArraySpec object

#pragma once

#include <string>
#include <list>
using std::list;
using std::string;

class ArraySpec
{
    public:
        ArraySpec()
        {}
        
        virtual string toString()
        {
            string temp = "(ARRAYSPEC: ";
            list<int>::const_iterator it;
            
            for (it = m_Array.begin(); it != m_Array.end(); it++)
                temp += std::to_string(*it) + ' ';
                
            temp += ")\n";
            
            return temp;
        }
        
        void AddNode(int val)
        {
            m_Array.push_back(val);
        }
    private:
        list <int> m_Array;
        
};