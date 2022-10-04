//Jordan Rood
//Homework 2 - Linked Stack

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<class ItemType>
class stackInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const ItemType& newEntry) = 0;
    virtual bool pop() = 0;
    virtual ItemType peek() const = 0;
    virtual ~stackInterface() {}
};
#endif