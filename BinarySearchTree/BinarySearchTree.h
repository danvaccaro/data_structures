#include <iostream>

using KeyType = int;
using ValueType = std::string;

struct BSTNode
{
    KeyType key;
    ValueType val;
    BSTNode *left, *right;
    int count;
    BSTNode(KeyType key, ValueType val)
    {
        this->key = key;
        this->val = val;
        left = nullptr;
        right = nullptr;
        count = 1;
    }
    BSTNode(KeyType key, ValueType val, BSTNode *left, BSTNode *right)
    {
        this->key = key;
        this->val = val;
        this->left = left;
        this->right = right;
        count = 1;
    }
};

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool isEmpty();
    int getSize();
    bool contains(KeyType searchKey);
    void insert(KeyType key, ValueType value);
    void remove(KeyType key);
    ValueType lookup(KeyType key);
    KeyType min();
    KeyType max();
    void print();

private:
    BSTNode *root;
    int size;
    bool isEmpty(BSTNode *tree);
    bool contains(KeyType key, BSTNode *tree);
    BSTNode *insert(KeyType key, ValueType value, BSTNode *tree);
    BSTNode *remove(KeyType key, BSTNode *tree);
    BSTNode *lookup(KeyType key, BSTNode *tree);
    BSTNode *min(BSTNode *tree);
    BSTNode *max(BSTNode *tree);
    bool isLeaf(BSTNode *tree);
    void print(BSTNode *nodep);
    void deleteTree(BSTNode *nodep);
    bool hasOnlyLeftChild(BSTNode *nodep);
    bool hasOnlyRightChild(BSTNode *nodep);
};