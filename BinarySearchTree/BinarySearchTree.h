#include <iostream>

using KeyType = int;
using ValueType = std::string;

struct BSTNode
{
    KeyType key;
    ValueType val;
    BSTNode *left, *right;
};

class BinarySearchTree
{
public:
    bool isEmpty();
    int getSize();
    bool contains(KeyType searchKey);
    void insert(KeyType key, ValueType value);
    void remove(KeyType key);
    ValueType lookup(KeyType key);
    KeyType min();
    KeyType max();

private:
    BSTNode *root;
    int size;
    BSTNode *newNode(KeyType key, ValueType value, BSTNode *left, BSTNode *right);
    BSTNode *newNode(KeyType key, ValueType value);
    bool isEmpty(BSTNode *tree);
    bool contains(KeyType key, BSTNode *tree);
    KeyType min(BSTNode *tree);
    bool isLeaf(BSTNode *tree);
};