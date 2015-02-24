//Created By Casey Schurman
//Date: 2/9/2015
//Defines a FuncHeader object

#pragma once

#include "FuncPrefix.h"
#include "ParamsSpec.h"
#include "cSymbol.h"
#include <string>
using std::string;

class FuncHeader
{
    public:
        FuncHeader(FuncPrefix * prefix, ParamsSpec * parameters)
            : m_Prefix(prefix), m_Parameters(parameters)
        {}
        virtual string toString()
        {
            string temp = m_Prefix->toString();
            
            if (m_Parameters != nullptr)
                temp += ' ' + m_Parameters->toString();
            else
                temp += "()";
                
            return temp;
        }
        
        cSymbol* GetTypeSymbol()
        {
            return m_Prefix->GetTypeSymbol();
        }
        
        DeclNode * GetType()
        {
            return m_Prefix->GetType();
        }
    
    private:
        FuncPrefix * m_Prefix;
        ParamsSpec * m_Parameters;
};