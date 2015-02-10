//Created By Casey Schurman
//Date: 2/7/2015
//Defines an IfNode object

#pragma once

#include <string>
#include "StmtNode.h"
using std::string;

class IfNode : public StmtNode
{
    public:
        IfNode(ExprNode * val, StmtNode * stmt1, StmtNode * stmt2)
            : m_Value(val), m_Stmt1(stmt1), m_Stmt2(stmt2)
        {}
        virtual string toString()
        {
            string temp = "(IF: " + m_Value->toString() + "\n" + m_Stmt1->toString() + "\n";
            
            if (m_Stmt2 != nullptr)
                temp += "ELSE:\n" + m_Stmt2->toString() + "\n";
                
            temp += ")";
            
            return temp;
        }
    
    private:
        ExprNode * m_Value;
        StmtNode * m_Stmt1;
        StmtNode * m_Stmt2;
};