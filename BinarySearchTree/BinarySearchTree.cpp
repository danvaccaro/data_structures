#include "BinarySearchTree.h"


bool BinarySearchTree::isEmpty() {

}

BSTNode *BinarySearchTree::newNode(KeyType key, ValueType value, BSTNode * left, BSTNode *right)
{
    BSTNode *newNode = new BSTNode();
    newNode->key = key;
    newNode->val = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

BSTNode *BinarySearchTree::newNode(KeyType key, ValueType value)
{
    BSTNode *newNode = new BSTNode();
    newNode->key = key;
    newNode->val = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool BinarySearchTree::isEmpty(BSTNode *tree) {
    if(tree = nullptr)
        return true;
    return false;
}

bool BinarySearchTree::isLeaf (BSTNode *tree) {

}

int BinarySearchTree::getSize() {
    return size;
}
