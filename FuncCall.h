//Created By Casey Schurman
//Date: 2/9/2015
//Defines a FuncCall object

#pragma once

#include "cSymbol.h"
#include "ParamsNode.h"
#include "StmtNode.h"
#include "ExprNode.h"
#include "DeclNode.h"

class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(cSymbol * ID, ParamsNode * parameters)
            : m_ID(ID), m_Parameters(parameters)
        {}
        virtual string toString()
        {
            return "(FUNC CALL: " + m_ID->toString() + m_Parameters->toString() + ")\n";
        }
        
        DeclNode * GetType()
        {
            return m_ID->GetType();
        }
    
    private:
        cSymbol * m_ID;
        ParamsNode * m_Parameters;
};