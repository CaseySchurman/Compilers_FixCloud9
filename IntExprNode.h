//Created By Casey Schurman
//Date: 2/7/2015
//Defines an IntExprNode object

#pragma once

#include "ExprNode.h"
#include <string>
using std::string;

class IntExprNode : public ExprNode
{
    public:
        IntExprNode(int val) : m_val(val)
        {}
        
        string toString()
        {
            return "(EXPR: " + std::to_string(m_val) + ")";
        }
    private:
        int m_val;
};
