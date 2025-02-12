#pragma once

#include "NodeInterface.h"

#include <iostream>

class Node : public NodeInterface {

public:
    Node();
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(const int& the_data,
           Node* left_val = NULL,
           Node* right_val = NULL) :
           data(the_data), leftChild(left_val),  rightChild(right_val) {}

    ~Node();

    int getData() const;

    NodeInterface * getLeftChild() const;

    NodeInterface * getRightChild() const;

};