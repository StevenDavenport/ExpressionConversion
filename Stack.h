//
// Created by steven on 29/12/2020.
//

#ifndef INFIXPOSTFIXPREFIX_STACK_H
#define INFIXPOSTFIXPREFIX_STACK_H

#include "Node.h"
#include <cstdio>

// Abstract Data Type Last in First out Stack data structure.
// The data type is generic and is defined when a linked list
// object is instantiated.
// The capacity of the linked list is defined when instantiated
// as is passed as a parameter to the constructor.
// However, if no capacity is stated, there will be no capacity
// size limit of the stack, one benefit of the linked list structure.
template <typename T>
class Stack
{
private:
    // Pointer containing the address of the top node of the linked list.
    Node<T>* top = nullptr;

    // Capacity is used to put a fixed size on the linked list,
    // does not need to be used, as there does not need to be a
    // fixed size
    int capacity;

    // The number of nodes that contain values currently in the
    // linked list.
    int currentSize;

public:
    // Constructor used if user wishes to define a capacity.
    explicit Stack(int size) : capacity(size)
    {
            currentSize = 0;
    }

    // Constructor used if the user does not wish to define a capacity.
    Stack()
    {
            capacity = -1;
            currentSize = 0;
    }

    // Adds a new node into the stack maintaining LIFO structure.
    void push(T val)
    {
            // If there is space for an item to be pushed
            // or there is no capacity.
            if (currentSize < capacity || capacity == -1)
            {
                    // List is currently empty
                    if (currentSize <= 0)
                    {
                            if (!top) top = new Node<T>();
                            top->value = val;
                    }
                    // Stack is not empty
                    else
                    {
                            auto* temp = new Node<T>();
                            temp->value = val;
                            temp->next = top;
                            top = temp;
                    }
                    ++currentSize;
            }
    }

    // Removes top from the stack and returns it's value.
    // If top is null (stack is empty) return null
    T pop()
    {
            if (top)
            {
                    auto* temp = top;
                    T val = temp->value;
                    top = top->next;
                    currentSize--;
                    delete(temp);
                    return val;
            }
            else
            {
                    return NULL;
            }
    }

    // Returns the value of ever node in the stack concatenated
    T popFull()
    {
            auto* temp = top;
            T result;
            while (temp)
            {
                   result+= temp->value;
                   temp = temp->next;
            }
            return result;
    }

    // Returns a the value of the top node,
    // if that node is null (stack empty),
    // return null.
    T peek()
    {
            return top ? top->value : NULL;
    }

    // Returns true if the stack is full
    bool isFull()
    {
            return currentSize >= capacity;
    }

    // Returns true if the stack is empty
    bool isEmpty()
    {
            return currentSize <= 0;
    }
};

#endif //INFIXPOSTFIXPREFIX_STACK_H

