//Created By Casey Schurman
//Date: 2/7/2015
//Defines an AssignNode object

#pragma once
#include "StmtNode.h"
#include "ExprNode.h"
#include "VarRef.h"
#include <string>
using std::string;

class AssignNode : public StmtNode
{
    public:
        AssignNode(VarRef * left, ExprNode * right)
            : m_Left(left), m_Right(right)
        {}
        virtual string toString()
        {
            return "(ASSIGN: " + m_Left->toString() + " = " + m_Right->toString() + ")";
        }
        
    private:
        VarRef * m_Left;
        ExprNode * m_Right;
};