/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:50 PM
 */

#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "node.h"
#include <iostream>

class TerminalNode: public Node{
public:
    TerminalNode(unsigned int size):Node(size){}
    
    virtual ~TerminalNode(){};
    
    virtual void print() const{cout<<"file size="<<m_size<<"); ";}
    
    virtual void Accept(Visitor* v) {v->VisitTerminalNode(this);}
};

#endif /* TERMINALNODE_H */

