//Created By Casey Schurman
//Date: 2/8/2015
//Defines a ParamNode object

#pragma once

#include "ExprNode.h"

class ParamNode
{
    public:
        ParamNode(ExprNode * expr) : m_Expr(expr)
        {}
        virtual string toString()
        {
            return m_Expr->toString();
        }
    
    private:
        ExprNode * m_Expr;
};