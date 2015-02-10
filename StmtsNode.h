//Created By Casey Schurman
//Date: 2/3/2015
//Defines a StmtsNode object

#pragma once

#include <list>
#include <string>
#include "cAstNode.h"
#include "StmtNode.h"
using std::list;
using std::string;

class StmtsNode : cAstNode
{
    public:
        StmtsNode(StmtNode * node)
        {
            AddNode(node);
        }
        virtual string toString()
        {
            string temp = " STMTS: \n{\n";
            list<StmtNode*>::const_iterator it;
            
            for (it = mStmtList.begin(); it != mStmtList.end(); it++)
            {
                temp += (*it)->toString() + '\n';
            }
            
            temp += "\n}";
            
            return temp;
        }
        void AddNode(StmtNode * node)
        {
            mStmtList.push_back(node);
        }
    
    private:
        list<StmtNode *> mStmtList;
};