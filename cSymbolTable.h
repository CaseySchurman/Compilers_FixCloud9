#pragma once
//Author: Casey Schurman
//1/20/15

#ifndef CSYMBOLTABLE_H
#define CSYMBOLTABLE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include "BaseDeclNode.h"
#include "cSymbol.h"
using std::string;
using std::unordered_map;
using std::list;

class cSymbolTable
{
    public:
        cSymbolTable()
        {
            unordered_map<string,cSymbol*> * global_map = new unordered_map<string,cSymbol*>();
           
            
            cSymbol * sym = new cSymbol("char");
            global_map->insert( std::pair<string,cSymbol*>("char", sym));
            sym->SetIsType();
            sym->SetType( new BaseDeclNode(1,false,"char"));

            sym = new cSymbol("int");
            sym->SetIsType();
            global_map->insert( std::pair<string,cSymbol*>("int", sym));
            sym->SetType(new BaseDeclNode(4, false,"int"));
            
            sym = new cSymbol("float");
            sym->SetIsType();
            global_map->insert( std::pair<string,cSymbol*>("float", sym));
            sym->SetType(new BaseDeclNode(8, true,"float"));
            
            mSymbolTables.push_front(global_map);
            
        }
        
        unordered_map<string,cSymbol*>* IncreaseScope()
        {
            unordered_map<string,cSymbol*> *newTable =  new unordered_map<string,cSymbol*>(); 
            mSymbolTables.push_front(newTable);
            return newTable;
        }
        
        void DecreaseScope()
        {
            mSymbolTables.pop_front();
        }
        
        cSymbol* InsertSymbol(string key)
        {
            cSymbol * symbol = CurLookup(key);
            if(symbol == nullptr)
            {
                symbol = new cSymbol(key);
                std::pair<string, cSymbol *> pear (key, symbol);
                mSymbolTables.front()->insert(pear);
            }
            return symbol;
        }
        
        cSymbol* InsertSymbol(cSymbol* sym)
        {
            cSymbol * symbol = CurLookup(sym->GetName());
            if(symbol == nullptr)
                mSymbolTables.front()->insert(std::pair<string,cSymbol*>(sym->GetName(), sym));
            else
                sym = symbol;
            return sym;
        }
        
        cSymbol * FullLookup(string target)
        {
            cSymbol* found = nullptr;
            
            list<unordered_map<string,cSymbol*>*>::iterator lit;
            for(lit = mSymbolTables.begin(); lit != mSymbolTables.end(); ++lit)
            {
                unordered_map<string,cSymbol*>::iterator it = (*lit)->find(target);
                if(it != (*lit)->end())
                    found = it->second;
            }
            
            return found;
            
        }
        
        
        cSymbol * CurLookup(string target)
        {   
           unordered_map<string, cSymbol *>::const_iterator found =  mSymbolTables.front()->find(target);
           if ( found == mSymbolTables.front()->end() )
           {
               return nullptr;
           }
           else
           {
               return found->second;
           }
        }

    private:
        list<unordered_map<string,cSymbol*>*> mSymbolTables;
};
#endif