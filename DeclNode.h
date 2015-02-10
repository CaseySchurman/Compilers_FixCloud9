//Created By Casey Schurman
//Date: 2/7/2015
//Defines an DeclNode object

#pragma once

#include "cAstNode.h"
#include <string>
using std::string;

class DeclNode
{
    public:
        virtual string toString() = 0;
};