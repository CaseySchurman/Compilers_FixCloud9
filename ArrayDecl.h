/***********************************************
 * Author: Casey Schurman
 *  
 * Purpose: To print the string for declaring an
 *          array.
 ***********************************************/
#pragma once

#include "DeclNode.h"
#include "cSymbol.h"
#include "ArraySpec.h"
#include "DeclNode.h"
#include <string>
using std::string;

class ArrayDecl : public DeclNode
{
    public:
        ArrayDecl(cSymbol * type, cSymbol * sym, ArraySpec * spec)
            : m_Type(type), m_Sym(sym), m_Spec(spec)
        {}
        
        virtual string toString()
        {
            string ret = "ARRAY: " + m_Type->toString() + ' ' + m_Sym->toString();
            
            if(m_Spec != nullptr)
            {
                ret += m_Spec->toString();
            }
            
            return ret;
        }
        
        int GetSize()
        {
            return -15;
        }
        
        string GetTypeName()
        {
            return m_Type->GetName();
        }
        
    private:
        cSymbol * m_Type;
        cSymbol * m_Sym;
        ArraySpec * m_Spec;    
};