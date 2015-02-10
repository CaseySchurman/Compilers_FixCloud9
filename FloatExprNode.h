//Created By Casey Schurman
//Date: 2/5/2015
//Defines an FloatExprNode object

#pragma once

#include "ExprNode.h"
#include <string>
using std::string;

class FloatExprNode : public ExprNode
{
    public:
        FloatExprNode(double val) : m_val(val)
        {}
        
        string toString()
        {
            return "(EXPR: " + std::to_string(m_val) + ")";
        }
    private:
        double m_val;
};
