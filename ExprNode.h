#pragma once

#include "DeclNode.h"
#include <string>
using std::string;

class ExprNode : public cAstNode
{
    public:
        virtual string toString() = 0;
        virtual DeclNode * GetType() =  0;

};