//Created By Casey Schurman
//Date: 2/7/2015
//Defines an DeclsNode object

#pragma once

#include "DeclNode.h"
#include <string>

using std::string;

class DeclsNode
{
    public:
        DeclsNode()
        {}
        
        virtual string toString()
        {
            string temp = "DECLS:\n{\n";
            list<DeclNode*>::const_iterator it = mDecls.begin();
            
            while (it != mDecls.end())
            {
                temp += (*it)->toString() + '\n';
                it++;
            }
            
            temp += "}\n";
            
            return temp;
        }
        
        void AddNode(DeclNode * nn)
        {
            mDecls.push_back(nn);
        }
    
    private:
        list <DeclNode*> mDecls;
};