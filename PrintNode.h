//Created By Casey Schurman
//Date: 2/1/2015
//Defines a PrintNode object

#pragma once
#include "StmtNode.h"
#include "ExprNode.h"
#include <string>
using std::string;

class PrintNode : public StmtNode
{
    public:
        PrintNode(ExprNode * value) : m_value(value)
        {}
        string toString()
        {
            return "PRINT: " + m_value->toString();
        }
    private:
        ExprNode * m_value;
};