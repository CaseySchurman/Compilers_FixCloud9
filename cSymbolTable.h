//Author: Casey Schurman
//1/20/15

#ifndef CSYMBOLTABLE_H
#define CSYMBOLTABLE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include "cSymbol.h"
using std::string;
using std::unordered_map;
using std::stack;

class cSymbolTable
{
    public:
        cSymbolTable()
        {
            mSymbolTables = new stack<unordered_map<string,cSymbol *>>;
        }
        
        void IncreaseScope()
        {
            unordered_map<string,cSymbol*> newTable; 
            mSymbolTables->push(newTable);
        }
        
        void DecreaseScope()
        {
            mSymbolTables->pop();
        }
        
        void InsertSymbol(string key, cSymbol * symbol)
        {
            std::pair<string, cSymbol *> pear (key, symbol);
            mSymbolTables->top().insert(pear);
        }
        
        cSymbol * FullLookup(string target)
        {
            stack<unordered_map<string,cSymbol*>> * copy = new stack<unordered_map<string,cSymbol*>>;
            bool found = false;
            cSymbol * temp = CurLookup(target);

            while (mSymbolTables->empty() == false && found == false && temp == nullptr)
            {
                temp = CurLookup(target);
                if(temp != nullptr)
                    found = true;
                else
                {
                    copy->push(mSymbolTables->top());
                    mSymbolTables->pop();
                }
            }
            while(copy->empty() != false)
            {
                mSymbolTables->push(copy->top());
                copy->pop();
            }
            delete copy;
            return temp;
        }

        cSymbol * CurLookup(string target)
        {   
           unordered_map<string, cSymbol *>::const_iterator found =  mSymbolTables->top().find(target);
           if ( found == mSymbolTables->top().end() )
           {
               return nullptr;
           }
           else
           {
               return found->second;
           }
        }

    private:
        stack<unordered_map<string,cSymbol*>> * mSymbolTables;
};
#endif