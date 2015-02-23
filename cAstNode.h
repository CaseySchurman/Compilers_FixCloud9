#pragma once
#include <string>
using std::string;

void semantic_error(std::string msg);

class cAstNode
{
    public:
        virtual string toString() = 0;
        
        virtual bool SemanticError()
        {
            return m_IsValid;
        }
        
        /*virtual string GetErrorMessage()
        {
            return m_ErrorMsg;
        }*/
        
    protected:
        bool m_IsValid;
        //string m_ErrorMsg;
};