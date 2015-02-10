//Created By Casey Schurman
//Date: 2/1/2015
//Defines a ReturnNode object

#pragma once

#include <string>
#include "StmtNode.h"
using std::string;

class ReturnNode : public StmtNode
{
    public:
        ReturnNode(ExprNode * val) : m_Value(val)
        {}
        virtual string toString()
        {
            return "RETURN: " + m_Value->toString();
        }
    
    private:
        ExprNode * m_Value;
};