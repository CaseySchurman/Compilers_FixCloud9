//Created By Casey Schurman
//Date: 2/8/2015
//Defines a StructDeclNode object

#pragma once

#include "DeclsNode.h"
#include "DeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class StructDeclNode : public DeclNode
{
    public:
        StructDeclNode(cSymbolTable * symTable, DeclsNode * decl, cSymbol * ID)
            : m_Symbols(symTable), m_Decl(decl), m_ID(ID)
        {}
        virtual string toString()
        {
            return "STRUCT: " + m_Decl->toString() + ' ' + m_ID->toString();
        }
    
    private:
        cSymbolTable * m_Symbols;
        DeclsNode * m_Decl;
        cSymbol * m_ID;
};