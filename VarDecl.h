//Created By Casey Schurman
//Date: 2/8/2015
//Defines a VarDecl object

#pragma once

//#include "DeclNode.h"
#include "ArraySpec.h"
#include "DeclNode.h"
#include <string>
using std::string;

class VarDecl : public DeclNode
{
    public:
        VarDecl(cSymbol * type, cSymbol * sym)
            : m_Type(type), m_Sym(sym)
        {}
        
        virtual string toString()
        {
            string ret = "VAR: " + m_Type->toString() + ' ' + m_Sym->toString();
            
            return ret;
        }
        
        bool IsInt()
        {
            return m_Type->GetType()->IsInt();
        }
        
        bool IsFloat()
        {
            return m_Type->GetType()->IsFloat();
        }
        
        int GetSize()
        {
            return -120;
        }
        
        string GetTypeName()
        {
            return m_Type->GetName();
        }
        
        DeclNode * GetBaseType()
        {
            return m_Sym->GetType();
        }
        
    private:
        cSymbol * m_Type;
        cSymbol * m_Sym;
};