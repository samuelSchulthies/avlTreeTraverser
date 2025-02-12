#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
    cout << "In node Constructor" << endl;
}
Node::~Node() {
    cout << "In node Destructor" << endl;
}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const{
    cout << "In getData" << endl;
    return data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getLeftChild() const {
    cout << "In getLeftChild" << endl;
    if(leftChild == NULL){
        return NULL;
    }
    return leftChild;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getRightChild() const {
    cout << "In getRightChild" << endl;
    if (rightChild == NULL){
        return NULL;
    }
    return rightChild;
}
