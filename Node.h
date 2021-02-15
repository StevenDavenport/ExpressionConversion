//
// Created by steven on 29/12/2020.
//

#ifndef INFIXPOSTFIXPREFIX_NODE_H
#define INFIXPOSTFIXPREFIX_NODE_H

// Node Struct that is used by the Linked List class.
// Each Node contains a generic type value and a pointer
// pointing at the next node in the sequence.
// This structure is designed for a last in first out
// stack data structure.
template <typename T>
struct Node
{
    T value;
    Node* next;
};


#endif //INFIXPOSTFIXPREFIX_NODE_H
