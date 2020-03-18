/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrintVisitor.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:47 PM
 */

#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H

class PrintVisitor: public Visitor{
public:
    PrintVisitor(){};
    
    virtual ~PrintVisitor(){};
    
    virtual void VisitTerminalNode(TerminalNode* term_node){
        cout<<"(file name="<<term_node->getName()<<", file size="<<term_node->getSize()<<"); ";
    }
    
    virtual void VisitNonTerminalNode(NonTerminalNode* non_term){
        cout<<"Directory "<<non_term->getName()<<" contains: (";
        for(int i=0; i<non_term->getChildrenSize(); i++){
            non_term->getChild(i)->Accept(this);
        }
        cout<<"); ";
    }
    
};

#endif /* PRINTVISITOR_H */

