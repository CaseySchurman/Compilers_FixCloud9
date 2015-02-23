//Author: Casey Schurman
//1/20/15

#ifndef CSYMBOL_H
#define CSYMBOL_H

#include "DeclNode.h"
#include <iostream>
#include <string>
using std::string;
using std::to_string;

class cSymbol
{
    public:
        cSymbol()
        {
            mSequence = ++symbolCount;
        }
        
        cSymbol(string symbol)
        {
            mSymbol = symbol;
            mSequence = ++symbolCount;
        }
        
        virtual string toString()
        {
            return "sym: " + mSymbol + " " + to_string(mSequence);
        }
        
        void SetSymbol(string symbol)
        {
            mSymbol = symbol;
        }
        
        string GetName()
        {
            return mSymbol;
        }
        
        DeclNode * GetType()
        {
            return m_Decl;
        }

        void SetType(DeclNode * type)
        {
            m_Decl = type;
        }
        
        void SetDeclared()
        {
            mIsDeclared = true;
        }
        
        bool GetDeclared()
        {
            return mIsDeclared;
        }
        
        void SetIsType()
        {
            mIsType = true;
        }
        
        bool IsType()
        {
            return mIsType;
        }
        
    protected:
        string mSymbol;
        int mSequence;
        static int symbolCount;
        DeclNode * m_Decl;
        bool mIsDeclared;
        bool mIsType;
};
#endif