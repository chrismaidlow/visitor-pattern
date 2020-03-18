/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:49 PM
 */

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "node.h"
#include <vector>
#include <iostream>
#include <algorithm>
class NonTerminalNode: public Node{
protected:
    vector<Node*> entries;
public:
    NonTerminalNode(unsigned int size):Node(size){};
    
    virtual ~NonTerminalNode(){};
    
    virtual void addChild(Node* entry){
        entries.push_back(entry);
    };
    
    virtual void removeChild(Node* entry){
        remove(entries.begin(), entries.end(), entry);
    };
    
    virtual Node* getChild(int i) const{
        return entries[i];
    };
    
    virtual unsigned int getChildrenSize() const{
        return entries.size();
    };
    
    virtual void print() const{
        cout<<"Directory "<<" contains: (";
        for(int i=0; i<entries.size(); i++){
            entries[i]->print();
        }
        cout<<"); ";
    };
    
    virtual void Accept(Visitor* v) {
        v->VisitNonTerminalNode(this);
    }
};

#endif /* NONTERMINALNODE_H */

