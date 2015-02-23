//Created By Casey Schurman
//Date: 2/7/2015
//Defines an IntExprNode object

#pragma once

#include "DeclNode.h"
#include "ExprNode.h"
#include <string>
using std::string;

extern cSymbolTable * symbolTableRoot;

class IntExprNode : public ExprNode
{
    public:
        IntExprNode(int val) : m_val(val)
        {}
        
        string toString()
        {
            return "(EXPR: " + std::to_string(m_val) + ")";
        }
        
        //Depending on value returns if a char or int
        DeclNode * GetType()
        {
            if(m_val > -129 && m_val < 128)
            {
                return symbolTableRoot->FullLookup("char")->GetType();
            }
            else
            {
                return symbolTableRoot->FullLookup("int")->GetType();
            }
        }
    private:
        int m_val;
};
