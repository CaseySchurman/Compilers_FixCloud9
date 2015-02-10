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
            unordered_map<string,cSymbol*> global_map;
           
            
            cSymbol * sym = new cSymbol("char");
            sym->SetType();
            global_map.insert( std::pair<string,cSymbol*>("char", sym));

            sym = new cSymbol("int");
            sym->SetType();
            global_map.insert( std::pair<string,cSymbol*>("int", sym));
            
            sym = new cSymbol("float");
            sym->SetType();
            global_map.insert( std::pair<string,cSymbol*>("float", sym));
            
            mSymbolTables->push(global_map);
            
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
        
        cSymbol* InsertSymbol(string key)
        {
            cSymbol * symbol = CurLookup(key);
            if(symbol == nullptr)
            {
                symbol = new cSymbol(key);
                std::pair<string, cSymbol *> pear (key, symbol);
                mSymbolTables->top().insert(pear);
            }
            return symbol;
        }
        
        cSymbol * FullLookup(string target)
        {
            stack<unordered_map<string,cSymbol*>> * copy = new stack<unordered_map<string,cSymbol*>>;
            cSymbol * temp = CurLookup(target);

            while (!mSymbolTables->empty() && temp == nullptr)
            {
                temp = CurLookup(target);
                if(temp == nullptr)
                {
                    copy->push(mSymbolTables->top());
                    mSymbolTables->pop();
                }
            }
            while(!copy->empty())
            {
                mSymbolTables->push(copy->top());
                copy->pop();
            }
            delete copy;
            return temp;
        }
        
        
        //This function is pretty worthless since your insert function shuold be doing this before inserting
        //a symbol
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