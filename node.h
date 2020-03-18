/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.h
 * Author: Chris
 *
 * Created on March 18, 2019, 9:51 PM
 */

#ifndef NODE_H
#define NODE_H

#include <string>
#include "visitor.h"

using namespace std;

class Node{
protected:
    unsigned int m_size;
    Node(unsigned int size): m_size(size){}
    
public:
    virtual ~Node(){};

    virtual unsigned int getSize() const{return m_size;}
    
    virtual void print() const=0;
    
    virtual void Accept(Visitor*) = 0;
};

#endif /* NODE_H */

