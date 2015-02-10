//Created By Casey Schurman
//Date: 2/8/2015
//Defines a Param object

#pragma once

#include "VarDecl.h"
#include <string>
using std::string;

class ParamSpec
{
    public:
        ParamSpec(VarDecl * decl) : m_Decl(decl)
        {}
        virtual string toString()
        {
            return m_Decl->toString();
        }
    
    private:
        VarDecl * m_Decl;
};