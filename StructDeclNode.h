//Created By Casey Schurman
//Date: 2/8/2015
//Defines a StructDeclNode object

#pragma once

#include "DeclsNode.h"
//#include "DeclNode.h"
#include "cSymbol.h"
#include "DeclNode.h"
#include <unordered_map>
using std::unordered_map;

class StructDeclNode : public DeclNode
{
    public:
        StructDeclNode(unordered_map<string,cSymbol*> * symTable, DeclsNode * decl, cSymbol * ID)
            : m_Symbols(symTable), m_Decl(decl), m_ID(ID)
        {}
        virtual string toString()
        {
            return "STRUCT: " + m_Decl->toString() + ' ' + m_ID->toString();
        }
        
        int GetSize()
        {
            return 25;
        }
        
        virtual bool IsStruct()
        {
            return true;
        }
        
        //Like lookups for SymbolTable, but in Struct Scope
        cSymbol* Find(string symbol)
        {
            cSymbol* sym = nullptr;
            
            if(m_Symbols != nullptr)
            {
                unordered_map<string,cSymbol*>::iterator it = m_Symbols->find(symbol);
                
                if(it != m_Symbols->end())
                {
                    sym = it->second;
                }
            }
            return sym;
        }
        
        string GetTypeName()
        {
            return m_ID->GetName();
        }
        
    private:
        unordered_map<string,cSymbol*> * m_Symbols;
        DeclsNode * m_Decl;
        cSymbol * m_ID;
};