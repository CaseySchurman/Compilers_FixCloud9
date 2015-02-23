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
                //Do this
                if(m_Left->GetType()->GetSize() < m_Right->GetType()->GetSize())
                {
                    //mLeft too small to hold mRight
                    m_IsValid = false;
                    semantic_error("Cannot assign " + m_Right->GetType()->GetTypeName() + " to a " + m_Left->GetType()->GetTypeName());
                }
            }
            else
            {
                //Valid assignment do nothing
            }
        }

    private:
        VarRef * m_Left;
        ExprNode * m_Right;
};