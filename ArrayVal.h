//Created By Casey Schurman
//Date: 2/7/2015
//Defines an ArrayVal object

#pragma once

#include "ExprNode.h"

class ArrayVal
{
    public:
        ArrayVal()
        {}
        virtual string toString()
        {
            string temp = "(ARRAYVAL: ";
            list<ExprNode*>::const_iterator it;
            
            for (it = mVals.begin(); it != mVals.end(); it++)
                temp += ' ' + (*it)->toString();
                
            temp += ")";
            
            return temp;
        }
        void AddNode(ExprNode * val)
        {
            mVals.push_back(val);
        }
        
    private:
        list<ExprNode*> mVals;
};