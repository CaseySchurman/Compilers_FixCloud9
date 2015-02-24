// Created By Casey Schurman
// Date: 2/7/2015
// Defines an ArraySpec object

#pragma once

#include <string>

#include <list>

class ArraySpec
{
    public:
        ArraySpec()
        {}
        
        virtual string toString()
        {
            std::string temp = "(ARRAYSPEC: ";
            std::list<int>::const_iterator it;
            
            for (it = m_Array.begin(); it != m_Array.end(); it++)
                temp += std::to_string(*it);
                
            temp += ")";
            
            return temp;
        }
        
        void AddNode(int val)
        {
            m_Array.push_back(val);
        }
    private:
        std::list <int> m_Array;
        
};