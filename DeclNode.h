//Created By Casey Schurman
//Date: 2/7/2015
//Defines an DeclNode object

#pragma once

#include "cAstNode.h"

class DeclNode : public cAstNode
{
    public:
        //Get size must be implemented by child classes
        virtual int GetSize() = 0;
        
        virtual bool IsType() 
        { 
            return true; 
        }
        
        virtual bool IsFloat()
        {
            return false;
        }
        
        virtual bool IsInt()
        {
            return false;
        }
        
        virtual bool IsChar()
        {
            return false;
        }
        
        virtual bool IsStruct()
        {
            return false;
        }
        
        virtual bool IsFunc()
        {
            return false;
        }
        
        virtual bool IsArray()
        {
            return false;
        }
        
        //GetTypeName must be implemented by child classes
        virtual string GetTypeName() = 0;
};