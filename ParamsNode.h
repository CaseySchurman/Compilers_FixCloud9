//Created By Casey Schurman
//Date: 2/8/2015
//Defines a ParamsNode object

#pragma once

#include "ParamNode.h"
#include "StmtNode.h"

class ParamsNode : public StmtNode
{
    public:
        ParamsNode()
        {}
        virtual string toString()
        {
            string temp = "(PARAM:";
            list<ParamNode*>::const_iterator it;
            
            for (it = mParameters.begin(); it != mParameters.end(); it++)
                temp += (*it)->toString() + ' ';
                
            temp += ")\n";
            
            return temp;
        }
        void AddNode(ParamNode * parameter)
        {
            mParameters.push_back(parameter);
        }
    
    private:
        list<ParamNode*> mParameters;
};