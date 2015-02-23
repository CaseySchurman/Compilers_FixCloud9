//Created By Casey Schurman
//Date: 2/9/2015
//Defines a FuncDecl object

#pragma once

#include "DeclNode.h"
#include "FuncHeader.h"
#include "DeclsNode.h"
#include "StmtsNode.h"

class FuncDecl : public DeclNode
{
    public:
        FuncDecl(FuncHeader * header, DeclsNode * decls, StmtsNode * stmts)
            : m_Header(header), m_Decls(decls), m_Stmts(stmts)
        {}
        virtual string toString()
        {
            string temp = "(FUNC: " + m_Header->toString();
            
            if (m_Decls != nullptr)
                temp += m_Decls->toString();
            
            if (m_Stmts != nullptr) 
                temp += m_Stmts->toString();
                
            temp += "\n)";
            
            return temp;
        }
        
        int GetSize()
        {
            return -150;
        }
        
        string GetTypeName()
        {
            return m_Header->GetTypeSymbol()->GetName();
        }
    
    private:
        FuncHeader * m_Header;
        DeclsNode * m_Decls;
        StmtsNode * m_Stmts;
};