//Created By Casey Schurman
//Date: 2/1/2015
//Defines a BlockNode object

#pragma once

#include <string>
#include "PrintNode.h"
#include "StmtsNode.h"
#include "DeclsNode.h"
#include "cAstNode.h"
#include "StmtNode.h"

using std::string;

class BlockNode : public StmtNode
{
    public:
        BlockNode(DeclsNode * decl, StmtsNode * stmts) : mDecls(decl), mStmts(stmts)
        {}
        virtual string toString()
        {
            string temp = "BLOCK: \n{\n";
            
            if (mDecls != nullptr)
                temp += mDecls->toString() + ' ' + mStmts->toString();
            if (mStmts != nullptr)
                temp += mStmts->toString();
                
            temp += "}\n";
            
            return temp;
        }
  
    private:
        DeclsNode * mDecls;
        StmtsNode * mStmts;
};