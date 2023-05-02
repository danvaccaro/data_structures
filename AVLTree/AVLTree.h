#include <iostream>

using KeyType = int;
using ValueType = std::string;

struct AVLNode
{
    KeyType key;
    ValueType val;
    AVLNode *left, *right;
    int count, height;
    AVLNode(KeyType key, ValueType val) : 
        key(key), val(val), 
        left(nullptr), right(nullptr), 
        count(1), height(0) {}
};

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    bool isEmpty() const;
    int getSize() const;
    bool contains(KeyType searchKey) const;
    void insert(KeyType key, ValueType value);
    void remove(KeyType key);
    AVLNode *lookup(KeyType key) const;
    void setValue(KeyType key, ValueType value);
    AVLNode *min() const;
    AVLNode *max() const;
    void print() const;

private:
    AVLNode *root;
    int size;
    bool isEmpty(AVLNode *tree) const;
    bool contains(KeyType key, AVLNode *tree) const;
    AVLNode *insert(KeyType key, ValueType value, AVLNode *tree);
    AVLNode *remove(KeyType key, AVLNode *tree);
    AVLNode *lookup(KeyType key, AVLNode *tree) const;
    AVLNode *min(AVLNode *tree) const;
    AVLNode *max(AVLNode *tree) const;
    void print(AVLNode *nodep) const;
    bool isLeaf(AVLNode *tree) const;
    void deleteTree(AVLNode *nodep);
    bool hasOnlyLeftChild(AVLNode *nodep) const;
    bool hasOnlyRightChild(AVLNode *nodep) const;
    AVLNode *rebalance(AVLNode *nodep);
    AVLNode *rotateLeft(AVLNode *nodep);
    AVLNode *rotateRight(AVLNode *nodep);
    int getHeight(AVLNode *nodep) const;
    void updateHeight(AVLNode *nodep);
    int heightDiff(AVLNode *nodep) const;
};