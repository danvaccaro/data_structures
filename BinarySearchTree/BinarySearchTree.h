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
    bool isEmpty() const;
    int getSize() const;
    bool contains(KeyType searchKey) const;
    void insert(KeyType key, ValueType value);
    void remove(KeyType key);
    BSTNode *lookup(KeyType key) const;
    void setValue(KeyType key, ValueType value);
    KeyType min() const;
    KeyType max() const;
    void print() const;

private:
    BSTNode *root;
    int size;
    bool isEmpty(BSTNode *tree) const;
    bool contains(KeyType key, BSTNode *tree) const;
    BSTNode *insert(KeyType key, ValueType value, BSTNode *tree);
    BSTNode *remove(KeyType key, BSTNode *tree);
    BSTNode *lookup(KeyType key, BSTNode *tree) const;
    BSTNode *min(BSTNode *tree) const;
    BSTNode *max(BSTNode *tree) const;
    void print(BSTNode *nodep) const;
    bool isLeaf(BSTNode *tree) const;
    void deleteTree(BSTNode *nodep);
    bool hasOnlyLeftChild(BSTNode *nodep) const;
    bool hasOnlyRightChild(BSTNode *nodep) const;
};