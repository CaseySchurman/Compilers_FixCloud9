//Created By Casey Schurman
//Date: 2/9/2015
//Defines a FuncPrefix object

#pragma once
#include "cSymbol.h"
#include "ParamsNode.h"
#include <string>
using std::string;

class FuncPrefix
{
    public:
        FuncPrefix(cSymbol * typeID, cSymbol * ID)
            : m_TypeID(typeID), m_ID(ID)
        {}
        
        virtual string toString()
        {
            return m_ID->toString();
        }
        
        cSymbol* GetTypeSymbol()
        {
            return m_TypeID;
        }
    
    private:
        cSymbol * m_TypeID;
        cSymbol * m_ID;
};