//Created By Casey Schurman
//Date: 2/5/2015
//Defines an FloatExprNode object

#pragma once

#include "DeclNode.h"
#include "ExprNode.h"
#include <string>
using std::string;

extern cSymbolTable * symbolTableRoot;

class FloatExprNode : public ExprNode
{
    public:
        FloatExprNode(double val) : m_val(val)
        {}
        
        string toString()
        {
            return "(EXPR: " + std::to_string(m_val) + ")";
        }
        
        DeclNode * GetType()
        {
           return symbolTableRoot->FullLookup("float")->GetType();
        }
    private:
        double m_val;
};
