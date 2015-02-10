//Author: Casey Schurman
//1/20/15

#ifndef CSYMBOL_H
#define CSYMBOL_H

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
        
        bool GetType()
        {
            return m_IsType;
        }
        
        void SetType()
        {
            m_IsType = true;
        }
        
        string GetName()
        {
            return mSymbol;
        }
        
    protected:
        string mSymbol;
        int mSequence;
        static int symbolCount;
        bool m_IsType;
};

#endif