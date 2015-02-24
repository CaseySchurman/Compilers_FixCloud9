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
        
        DeclNode * GetBaseType()
        {
            return m_Type->GetType();
        }
        string GetTypeName()
        {
            return m_Sym->GetName();    //this is better. Ur going to return like idata and fdata or whatever the array name is
            //return m_Type->GetName(); // here you are returning the type (like int, char etc. You want the name of the array. use m_Sym instead)
        }
        
        bool IsArray()
        {
            return true;
        }
        
    private:
        cSymbol * m_Type;
        cSymbol * m_Sym;
        ArraySpec * m_Spec;    
};