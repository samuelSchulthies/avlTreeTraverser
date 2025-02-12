#include "NodeInterface.h"
#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() {
    cout << "In constructor" << endl;
    root = NULL;
    treeSize = 0;
}
BST::~BST() {
    cout << "In destructor" << endl;
    clear();
}

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * BST::getRootNode() const{
    cout << "In getRoot" << endl;
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
    cout << "In add" << endl;
    return addHelp(root, data);
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/

bool BST::addHelp(Node *&ptr, int data){
    cout << "In addHelp" << endl;
    if (root == NULL) {
        ptr = new Node(data);
        root->data = data;
        treeSize++;
        return true;
    }
    else if(ptr == NULL){
        ptr = new Node(data);
        treeSize++;
        return true;
    }
    else if(ptr->data == data){
        cout << "Already in list" << endl;
        return false;
    }
    else if (ptr->data > data){
        return addHelp(ptr->leftChild, data);
    }
    else if(ptr->data < data){
        return addHelp(ptr->rightChild, data);
    }
    else{
        return false;
    }
}

bool BST::remove(int data){
    cout << "In remove" << endl;
    bool returnStatus = 0;

    removeHelp(root, data, returnStatus);

    return returnStatus;
}

bool BST::removeHelp(Node *&ptr, int data, bool &returnStatus){
    //Recursion
    cout << "In removeHelp" << endl;
    if (ptr->data > data){
        cout << "Recursing Left side" << endl;
        if (ptr->leftChild == NULL){
            cout << endl << "Data " << data << " is not in tree" << endl << endl;
            returnStatus = 0;
            return returnStatus;
        }
        removeHelp(ptr->leftChild, data, returnStatus);
    }
    else if (ptr->data < data){
        cout << "Recursing Right side" << endl;
        if (ptr->rightChild == NULL){
            cout << endl << "Data " << data << " is not in tree" << endl << endl;
            returnStatus = 0;;
            return returnStatus;
        }
        removeHelp(ptr->rightChild, data, returnStatus);
    }
    //Base cases
    else {
        if ((ptr->rightChild == NULL) && (ptr->leftChild == NULL)) { //If there are no children
            cout << endl << "ptr->data to be removed (no children): " << ptr->data << endl << endl;
            Node *temp = ptr;
            ptr = NULL;
            delete temp;
            returnStatus = 1;
            return returnStatus;
        }
        if ((ptr->rightChild != NULL) && (ptr->leftChild == NULL)) { //If leftChild is null
            cout << endl << "ptr->data to be removed (left child is null): " << ptr->data << endl << endl;
            Node *temp = ptr;
            ptr = ptr->rightChild;
            delete temp;
            returnStatus = 1;
            return returnStatus;
        }
        if ((ptr->rightChild == NULL) && (ptr->leftChild != NULL)) { //If rightChild is null
            cout << endl << "ptr->data to be removed (right child is null): " << ptr->data << endl << endl;
            Node *temp = ptr;
            ptr = ptr->leftChild;
            delete temp;
            returnStatus = 1;
            return returnStatus;
        }
        if ((ptr->rightChild != NULL) && (ptr->leftChild != NULL)) { //If both children are not null
            cout << endl << "ptr->data to be removed (two children): " << ptr->data << endl << endl;
            int inOrderPred = getInOrderPredValue(ptr);
            ptr->data = inOrderPred;
            removeHelp(ptr->leftChild, inOrderPred, returnStatus);
        }
    }
    return true;
}

int BST::getInOrderPredValue(Node *ptr){
    ptr = ptr->leftChild;
    while(ptr->rightChild != NULL){
        ptr = ptr->rightChild;
    }
    return ptr->data;
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear(){
    cout << "In clear" << endl;
    while (root != NULL){
        remove(root->data);
    }
}