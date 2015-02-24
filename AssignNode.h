//Created By Casey Schurman
//Date: 2/7/2015
//Defines an AssignNode object

#pragma once
#include "StmtNode.h"
#include "ExprNode.h"
#include "VarRef.h"
#include <string>
using std::string;

class AssignNode : public StmtNode
{
    public:
        AssignNode(VarRef * left, ExprNode * right)
            : m_Left(left), m_Right(right)
        {
            CheckValidity();
        }
        
        virtual string toString()
        {
            return "(ASSIGN: " + m_Left->toString() + " = " + m_Right->toString() + ")";
        }
        
        void CheckValidity()
        {
            m_IsValid = true;
            if(m_Left->GetType() != m_Right->GetType())
            {
                DeclNode* lft = m_Left->GetType();
                DeclNode* rgt = m_Right->GetType();
                bool err = false;
                
                if(lft->IsChar())
                    err = true;
                else if(lft->IsInt() && (rgt->IsFloat() || rgt->IsStruct()))
                    err = true;
                else if(lft->IsFloat() && rgt->IsStruct())
                    err = true;
                else if(lft->IsStruct() && (rgt->IsInt() || rgt->IsFloat() || rgt->IsChar()))
                    err = true;
                else if(lft->IsStruct() && rgt->IsStruct())
                {
                    if(lft->GetTypeName() != rgt->GetTypeName())
                        err = true;
                }
                else if ((!lft->IsArray() && rgt->IsArray()) || (lft->IsArray() && !rgt->IsArray())) 
                    err = true;
                else if ((lft->IsArray() && rgt->IsArray()) && (lft->GetTypeName() != rgt->GetTypeName()))
                    err = true;
                //Do this
                if(err)
                {
                    //mLeft too small to hold mRight
                    m_IsValid = false;
                    semantic_error("Cannot assign " + m_Right->GetType()->GetTypeName() + " to a " + m_Left->GetType()->GetTypeName());
                }
            }
            
        }

    private:
        VarRef * m_Left;
        ExprNode * m_Right;
};