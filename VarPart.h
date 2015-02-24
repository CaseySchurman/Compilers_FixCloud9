//Created By Casey Schurman
//Date: 2/8/2015
//Defines a VarPart object

#pragma once

#include "ExprNode.h"
#include "cSymbol.h"
#include "ArrayVal.h"
#include "ArrayDecl.h"

extern cSymbolTable * symbolTableRoot;

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
        
        //Return's Type of Symbol
        DeclNode * GetType()
        {
            if(m_Array == nullptr)
            {
                return m_Sym->GetType();
            }
            else
            {
                return m_Sym->GetType()->GetBaseType();
            }
        }
        
        cSymbol * GetSym()
        {
            return m_Sym;
        }
        
        void SetSym(cSymbol * sym)
        {
            m_Sym = sym;
        }
    
    private:
        cSymbol * m_Sym;
        ArrayVal * m_Array;
};