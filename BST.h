#pragma once

#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {

public:
    BST();
    BST(const int the_data,
            const BST& left_child = BST(),
            const BST& right_child = BST()):
            root(new Node(the_data, left_child.root, right_child.root)) {}
    ~BST();

    NodeInterface * getRootNode() const;

    bool add(int data);

    bool addHelp(Node *&ptr, int data);

    bool remove(int data);

    bool removeHelp(Node *&ptr, int data, bool &returnStatus);

    int getInOrderPredValue(Node *ptr);

    void clear();

protected:
    Node *root;
    int treeSize;
};