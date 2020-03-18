/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   visitor.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:42 PM
 */

#ifndef VISITOR_H
#define VISITOR_H

class NonTerminalNode;
class TerminalNode;

class Visitor{
public:
    Visitor(){};
    virtual ~Visitor(){};
    virtual void VisitTerminalNode(TerminalNode*)=0;
    virtual void VisitNonTerminalNode(NonTerminalNode*)=0;    
};

#endif /* VISITOR_H */

