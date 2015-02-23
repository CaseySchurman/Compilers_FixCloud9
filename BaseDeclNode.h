/***********************************************
 * Author: Casey Schurman
 *  
 * Purpose: The base node for most decl nodes
 ***********************************************/

#pragma once

#include "DeclNode.h"

#include <string>
using std::string;

class BaseDeclNode : public DeclNode
{
  public:
    BaseDeclNode(int size, bool isFloat, string type)
        :m_Size(size), m_IsFloat(isFloat), m_TypeName(type)
    {}
    
    virtual string toString()
    {
        return "Found a BaseDeclNode!";
    }
    
    virtual bool IsInt()   
    { 
        return !m_IsFloat;
    }
    
    
    virtual bool IsFloat() 
    { 
        return m_IsFloat; 
    }
    
    int GetSize()
    {
        return m_Size;
    }
    
    string GetTypeName()
    {
        return m_TypeName;
    }

  protected:
    int m_Size;
    bool m_IsFloat;
    string m_TypeName;
};
