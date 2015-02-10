//Created By Casey Schurman
//Date: 2/8/2015
//Defines a VarDecl object

#pragma once

#include "DeclNode.h"
#include "ArraySpec.h"
#include <string>
using std::string;

class VarDecl : public DeclNode
{
    public:
        VarDecl(cSymbol * type, cSymbol * sym, ArraySpec * spec)
            : m_Type(type), m_Sym(sym), m_Spec(nullptr)
        {}
        virtual string toString()
        {
            return "VAR: " + m_Type->toString() + ' ' + m_Sym->toString();
        }
        
    private:
        cSymbol * m_Type;
        cSymbol * m_Sym;
        ArraySpec * m_Spec;
};