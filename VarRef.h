//Created By Casey Schurman
//Date: 2/8/2015
//Defines a VarRef object

#pragma once

#include "ExprNode.h"
#include "VarPart.h"
#include "StructDeclNode.h"


class VarRef : public ExprNode
{
    public:
        VarRef()
        {}
        
        virtual string toString()
        {
            string retVal = "";
    

            list<VarPart*>::iterator it;
    

            for(it = m_parts.begin(); it != m_parts.end(); ++it )
            {

                retVal += "(VarRef: " + (*it)->toString();
        
            }
            
            for (size_t i = m_parts.size() -1 ; i >= 0; --i)
            {
                retVal += ')';
            }
            
            return retVal;
        }
        
        void AddNode(VarPart * part)
        {
            m_IsValid = CheckValidity(part);
            if(!m_IsValid)
                m_parts.push_back(part);
        }
        
        DeclNode * GetType()
        {
            return m_parts.back()->GetType();
        }
        
        bool CheckValidity(VarPart* symbol)
        {
            
            if(m_parts.size() == 0)
            {
                
                if(!symbol->GetSym()->GetDeclared())
                {
                    semantic_error("Symbol " + symbol->GetSym()->GetName() + " not defined");
                    return true;
                }
            }
            else
            {
                
                StructDeclNode* decl = dynamic_cast<StructDeclNode*>(m_parts.back()->GetType());
                
                // If it was able to convert to a struct decl...
                if (decl != nullptr)
                {
                    // Find the symbol in the struct that it belongs to
                    cSymbol * sym = decl->Find(symbol->GetSym()->GetName());
                    
                    // If we find it in the struct...
                    if(sym != nullptr)
                    {
                        symbol->SetSym(sym);
                        return false; // No error
                    }
                    else // else, we didn't find the symbol in the struct, return the error
                    {
                        string StructErrorMsg = symbol->GetSym()->GetName() + " is not a field of ";
                        
                        
                        
                        semantic_error(StructErrorMsg+BuildStruct());
                        
                        return true; // Error
                    }
                }
                else //Else decl was not a struct decl
                {
                    semantic_error(BuildStruct() + " is not a struct");
                    return true;
                }
            }
            
            //return true so compiler won't complain
            return false;
        }
        
        string BuildStruct()
        {
            string StructErrorMsg = "";
            list<VarPart*>::const_iterator it = m_parts.begin();
            int counter = m_parts.size() - 1;

            // Iterate through list of parts displaying them
            while (it != m_parts.end())
            {
                StructErrorMsg += (*it)->GetSym()->GetName(); // Add to the error message
    
                it++; // Move iterator to the next VarPart
    
                // If the iterator has not displayed the last Varpart
                // add a '.' to differentiate between the different parts
                if (counter != 0)
                {
                    StructErrorMsg += '.';
                }
        
                counter--;
            }
            return StructErrorMsg;
        }
        
    private:
        list<VarPart*> m_parts;
};