#pragma once

#include <string>

using std::string;

class ExprNode 
{
    public:
        virtual string toString() = 0;
};