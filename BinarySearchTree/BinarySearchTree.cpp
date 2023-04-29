#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    deleteTree(root);
}
void BinarySearchTree::deleteTree(BSTNode *nodep)
{
    if (not isEmpty(nodep))
    {
        deleteTree(nodep->right);
        deleteTree(nodep->left);
        delete nodep;
    }
}

bool BinarySearchTree::isEmpty()
{
    return isEmpty(root);
}

bool BinarySearchTree::isEmpty(BSTNode *nodep)
{
    // if the node is nullptr, it is empty
    return nodep == nullptr;
}

int BinarySearchTree::getSize()
{
    return size;
}

bool BinarySearchTree::contains(KeyType searchKey)
{
    return contains(searchKey, root);
}

bool BinarySearchTree::contains(KeyType searchKey, BSTNode *tree)
{
    // case 1: tree is empty
    if (isEmpty(tree))
        return false;
    // recursive cases: utilize BST invariant and split tree
    else if (searchKey < tree->key)
        return contains(searchKey, tree->left);
    else if (searchKey > tree->key)
        return contains(searchKey, tree->right);
    // otherwise the key was found, return true
    else
        return true;
}

void BinarySearchTree::insert(KeyType key, ValueType value)
{
    root = insert(key, value, root);
    size++;
}

BSTNode *BinarySearchTree::insert(KeyType key, ValueType value, BSTNode *tree)
{
    if (isEmpty(tree))
        return new BSTNode(key, value);
    else if (key == tree->key)
    {
        tree->count++;
    }
    else if (key < tree->key)
    {
        tree->left = insert(key, value, tree->left);
    }
    else if (key > tree->key)
    {
        tree->right = insert(key, value, tree->right);
    }
    return tree;
}

void BinarySearchTree::remove(KeyType key)
{
    if (contains(key))
    {
        root = remove(key, root);
    }
    else
        std::cerr << key << " not found in tree :(\n";
}

BSTNode *BinarySearchTree::remove(KeyType key, BSTNode *tree)
{
    // case 1: empty tree
    if (isEmpty(tree))
        return nullptr;
    // case 2: the key is less than the current root's key
    else if (key < tree->key)
        tree->left = remove(key, tree->left);
    else if (key > tree->key)
        tree->right = remove(key, tree->right);
    else
    {
        if (tree->count > 1)
            tree->count--;
        else if (isLeaf(tree))
        {
            delete tree;
            return nullptr;
        }
        else if (hasOnlyLeftChild(tree))
        {
            BSTNode *newRoot = tree->left;
            delete tree;
            return newRoot;
        }
        else if (hasOnlyRightChild(tree))
        {
            BSTNode *newRoot = tree->right;
            delete tree;
            return newRoot;
        }
        // else it has two children
        else
        {
            // copy the data from the minimum of the right subtree
            BSTNode *minOfRight = min(tree->right);
            tree->key = minOfRight->key;
            tree->val = minOfRight->val;
            // remove the min from the tree
            tree->right = remove(minOfRight->key, tree->right);
        }
    }
    return tree;
}

ValueType BinarySearchTree::lookup(KeyType key) {
    if (contains(key))
        return lookup(key, root)->val;
    return NULL;
}

BSTNode *BinarySearchTree::lookup(KeyType key, BSTNode *tree) {
        if (key < tree->key) 
            return lookup(key, tree->left);
        if (key > tree->key) 
            return lookup(key, tree->right);
        else
            return tree;
}

KeyType BinarySearchTree::min() {
    return min(root)->key;
}
BSTNode *BinarySearchTree::min(BSTNode *tree)
{
    if (isEmpty(tree->left))
    {
        return tree;
    }
    return min(tree->left);
}

KeyType BinarySearchTree::max() {
    return max(root)->key;
}
BSTNode *BinarySearchTree::max(BSTNode *tree)
{
    if (isEmpty(tree->right))
    {
        return tree;
    }
    return max(tree->right);
}

bool BinarySearchTree::isLeaf(BSTNode *nodep)
{
    return not isEmpty(nodep) and nodep->left == nullptr and nodep->right == nullptr;
}

void BinarySearchTree::print()
{
    print(root);
    std::cout << "\n";
}
void BinarySearchTree::print(BSTNode *nodep)
{
    if (not isEmpty(nodep))
    {
        std::cout << "Key: " << nodep->key << " Value: " << nodep->val << " Count: " << nodep->count << "\n";
        print(nodep->left);
        print(nodep->right);
    }
}

bool BinarySearchTree::hasOnlyLeftChild(BSTNode *nodep)
{
    return nodep->right == nullptr;
}

bool BinarySearchTree::hasOnlyRightChild(BSTNode *nodep)
{
    return nodep->left == nullptr;
}
