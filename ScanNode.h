//Created By Casey Schurman
//Date: 2/4/2015
//Defines a ScanNode object

#pragma once

#include <string>
#include "StmtNode.h"
using std::string;

class ScanNode : public StmtNode
{
    public:
        ScanNode(ExprNode * val) : m_Value(val)
        {}
        virtual string toString()
        {
            return "SCAN: " + m_Value->toString();
        }
    
    private:
        ExprNode * m_Value;
};