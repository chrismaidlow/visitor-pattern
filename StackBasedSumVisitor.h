/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedSumVisitor.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:45 PM
 */

#ifndef STACKBASEDSUMVISITOR_H
#define STACKBASEDSUMVISITOR_H

#include "Visitor.h"
#include "node.h"
#include <stack>

class StackBasedSumVisitor: public Visitor{
public:
    stack<unsigned int> m_stack;
public:
    StackBasedSumVisitor(){};
    virtual ~StackBasedSumVisitor(){};

    virtual void VisitTerminalNode(TerminalNode* term_node){m_stack.push(term_node->getSize());}
    
    virtual void VisitNonTerminalNode(NonTerminalNode* non_term){
        unsigned int sum = non_term->getSize(); 
        //Visit every children, store state information in m_stack.
        for(int i=0; i< non_term->getChildrenSize(); i++){
            non_term->getChild(i)->Accept(this);
        }
        //Get state information from m_stack, do calculation.
        for( int i=0; i<non_term->getChildrenSize(); i++ ){
            sum += m_stack.top();
            m_stack.pop();
        }		
        //Store state information in m_stack.
        m_stack.push(sum);	
    };
        
    double getResult() {
        unsigned int result =m_stack.top();
        m_stack.pop();
        return result;
    }

private:
    StackBasedSumVisitor(const StackBasedSumVisitor& orig){};
};

#endif /* STACKBASEDSUMVISITOR_H */

