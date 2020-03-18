/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonStackBasedSumVisitor.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:44 PM
 */

#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H

#include "Visitor.h"
#include "node.h"

class NonStackBasedSumVisitor: public Visitor{
protected:
    unsigned int sum;
public:
    NonStackBasedSumVisitor(){sum=0;};
    virtual ~NonStackBasedSumVisitor(){};
    
    virtual void VisitTerminalNode(TerminalNode* term_node){sum+=term_node->getSize();}
    
    virtual void VisitNonTerminalNode(NonTerminalNode* non_term);
    {
        sum += non_term->getSize(); 
        //Visit every children, store state information in m_stack.
        for(int i=0; i< non_term->getChildrenSize(); i++){
            non_term->getChild(i)->Accept(this);
        }	
    }
      
    double getResult();
    {
        unsigned int result =sum;
        sum=0;
        return result;
    }
   
    
private:
    NonStackBasedSumVisitor(const NonStackBasedSumVisitor& orig){};
};

#endif /* NONSTACKBASEDSUMVISITOR_H */

