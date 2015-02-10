//Created By Casey Schurman
//Date: 2//2015
//Defines a WhileNode object

#pragma once
#include <string>
#include "StmtNode.h"
using std::string;

class WhileNode : public StmtNode
{
    public:
        WhileNode(ExprNode * val, StmtNode * stmt)
            : m_Value(val), m_Stmt(stmt)
        {}
        virtual string toString()
        {
            return "(WHILE: " + m_Value->toString() + '\n' + m_Stmt->toString() + "\n)";
        }
    
    private:
        ExprNode * m_Value;
        StmtNode * m_Stmt;
};