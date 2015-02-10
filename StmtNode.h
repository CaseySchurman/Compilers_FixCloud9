//Created By Casey Schurman
//Date: 2/3/2015
//Defines a StmtNode object

#pragma once

#include <string>
#include "cAstNode.h"
using std::string;

class StmtNode : public cAstNode
{
    public:
        virtual string toString() = 0;
};