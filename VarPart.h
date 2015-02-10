#pragma once

#include "ExprNode.h"
#include "cSymbol.h"
//Created By Casey Schurman
//Date: 2/8/2015
//Defines a VarPart object

#include "ArrayVal.h"

class VarPart : public ExprNode
{
    public:
        VarPart(cSymbol * sym, ArrayVal * ary)
            : m_Sym(sym), m_Array(ary)
        {}
        virtual string toString()
        {
            string temp = m_Sym->toString();
            
            if (m_Array != nullptr)
                temp += '[' + m_Array->toString() + ']';
                
            return temp;
        }
    
    private:
        cSymbol * m_Sym;
        ArrayVal * m_Array;
};