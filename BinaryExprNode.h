//Created By Casey Schurman
//Date: 2/5/2015
//Defines an BinaryExprNode object

#pragma once

#include "DeclNode.h"
#include "ExprNode.h"
#include <string>
using std::string;

class BinaryExprNode : public ExprNode
{
    public:
        BinaryExprNode(ExprNode* expr1, char oper, ExprNode * expr2)
            : m_expr1(expr1), m_oper(oper), m_expr2(expr2)
        {}
        
        string toString()
        {
            return "(EXPR: " + m_expr1->toString() + " " + m_oper + " " + m_expr2->toString() + ")";
        }
        
        DeclNode * GetType()
        {
            DeclNode * left = m_expr1->GetType();
            DeclNode * right = m_expr2->GetType();
            
            if (left == right || left->IsFloat())
            {
                return left; // Return the float
            }
            else if (right->IsFloat())
            {
                return right; // Return the float
            }
            else
            {
                if (left->GetSize() == 4)
                {
                    return left; // Return the int
                }
                else if (right->GetSize() == 4)
                {
                    return right; // Return the int
                }
                else
                {
                    return left; // Both are chars so return either of them
                }
            }
        }
    private:
        ExprNode * m_expr1;
        char m_oper;
        ExprNode * m_expr2;
        
};