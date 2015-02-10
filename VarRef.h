//Created By Casey Schurman
//Date: 2/8/2015
//Defines a VarRef object

#pragma once

#include "ExprNode.h"
#include "VarPart.h"
#include <string>
using std::string;

class VarRef : public ExprNode
{
    public:
        VarRef()
        {}
        
        virtual string toString()
        {
            string retVal = "";
    

            list<VarPart*>::iterator it;
    

            for(it = m_parts.begin(); it != m_parts.end(); ++it )
            {

                retVal += "(VarRef: " + (*it)->toString();
        

                if(it != m_parts.begin())
                    retVal += ")";
                else if(m_parts.size() > 1)
                    retVal += "\n";
            }
    

                retVal += ")";
                return retVal;
        }
        
        void AddNode(VarPart * part)
        {
            m_parts.push_back(part);
        }
        
    private:
        list<VarPart*> m_parts;
};