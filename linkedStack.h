//Jordan Rood
//Homework 2 - Linked Stack

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "node.h"
#include "stackInterface.h"

template<class ItemType>
class linkedStack : public stackInterface<ItemType> {
    Node<ItemType>* topStackPtr;

public:
    linkedStack();
    linkedStack(const linkedStack<ItemType>&);
    
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
    
    ~linkedStack();
};
#include "linkedStack.cpp"
#endif