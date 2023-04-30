#include "BinarySearchTree.h"
//default constuctor, empty tree with null root
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
    size = 0;
}
//destructor deletes the tree starting at the root
BinarySearchTree::~BinarySearchTree()
{
    deleteTree(root);
}
//deleteTree
//Purpose: recursively deallocates memory for each node in the tree rooted at nodep
//Parameters: a pointer to the root BSTNode in the tree
//Returns: void, updates the tree instance
void BinarySearchTree::deleteTree(BSTNode *nodep)
{
    //if the node isn't empty, delete the left and right subtrees and then delete the node
    if (not isEmpty(nodep))
    {
        deleteTree(nodep->right);
        deleteTree(nodep->left);
        delete nodep;
    }
}
//isEmpty
//Purpose: checks if this tree is empty.
//Parameters: none.
//Returns: a bool, true if the root is empty, false otherwise
bool BinarySearchTree::isEmpty() const
{
    return isEmpty(root);
}
//isEmpty helper function
//Purpose: checks if any given subtree is empty
//Parameters: a pointer to a subtree
//Returns: true if the subtree root is null, false otherwise
bool BinarySearchTree::isEmpty(BSTNode *nodep) const
{
    // if the node is nullptr, it is empty
    return nodep == nullptr;
}
//getSize
//Purpose: retrieves the size of the tree.
//Parameters: none
//Returns: an int, the number of nodes in this tree
int BinarySearchTree::getSize() const
{
    return size;
}
//contains
//Purpose: checks if the tree contains a given key
//Parameters: a key to search
//Returns: true if the key is in the tree, false otherwise
bool BinarySearchTree::contains(KeyType searchKey) const
{
    return contains(searchKey, root);
}
//contains helper function
//purpose: checks if a given subtree contains a given key
//parameters: a key to search and a pointer to the root node in the subtree
//returns: true if the key is present, false otherwise
bool BinarySearchTree::contains(KeyType searchKey, BSTNode *tree) const
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
//insert
//purpose: inserts a key value pair into the tree
//parameters: a key and a value
//returns: void, updates the root and size members appropriately
void BinarySearchTree::insert(KeyType key, ValueType value)
{
    root = insert(key, value, root);
    size++;
}
//insert helper function
//purpose: recursively inserts a key-value pair into the subtree starting at a given node
//parameters: a key, a value, and a pointer the the root of the subtree
//returns: a pointer to the root of the subtree
BSTNode *BinarySearchTree::insert(KeyType key, ValueType value, BSTNode *tree)
{
    //case 1: empty tree, create a new node and insert it at the root
    if (isEmpty(tree))
        return new BSTNode(key, value);
    //case 2: key is a duplicate - reduce the count by 1
    else if (key == tree->key)
        tree->count++;
    //recursive case 1: key is less than root's key - insert into the left subtree
    else if (key < tree->key)
        tree->left = insert(key, value, tree->left);
    //recursive case 2: key is greater than root's key - insert into right subtree
    else if (key > tree->key)
        tree->right = insert(key, value, tree->right);
    //return the root of the subtree
    return tree;
}
// remove
// purpose: removes the node containing a given key from the tree
// parameters: a key to remove
// returns: void, deletes the node and updates pointers to the deleted node
void BinarySearchTree::remove(KeyType key)
{
    //if the tree contains the key, remove from the tree starting at the root
    if (contains(key))
        root = remove(key, root);
    //otherwise the key isn't in the tree. report to the user
    else
        std::cerr << key << " not found in tree :(\n";
}
//remove helper function
//purpose: removes the node associated with the key from the given subtree
//parameters: a key and the root of a subtree
//returns: a pointer to the root of the updated subtree
BSTNode *BinarySearchTree::remove(KeyType key, BSTNode *tree)
{
    // case 1: empty tree
    if (isEmpty(tree))
        return nullptr;
    // case 2: the key is less than the current root's key
    else if (key < tree->key)
        tree->left = remove(key, tree->left);
    // case 3: the key is greater than the current root's key
    else if (key > tree->key)
        tree->right = remove(key, tree->right);
    //case 4: the key is equal to the current root's key
    else
    {
        //if it's a duplicate key, reduce the count by 1
        if (tree->count > 1)
            tree->count--;
        //if the node is a leaf, delete the node and update the subtree root to null
        else if (isLeaf(tree))
        {
            delete tree;
            return nullptr;
        }
        //if the node only has a left child, point the new root to the node's left child
        //and free up node memory
        else if (hasOnlyLeftChild(tree))
        {
            BSTNode *newRoot = tree->left;
            delete tree;
            return newRoot;
        }
        //if the node only has a right child, point the new root to the node's right child
        //and free up node memory
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
            // remove the min from the right subtree
            tree->right = remove(minOfRight->key, tree->right);
        }
    }
    //return the root of the new tree
    return tree;
}
//lookup
//purpose: looks for a given key in the tree
//parameters: a key to search
//returns: a pointer to the node containing the key if it exists, nullptr otherwise
BSTNode *BinarySearchTree::lookup(KeyType key) const
{
    if (contains(key))
        return lookup(key, root);
    return nullptr;
}
//lookup helper function
//purpose: recursively searches for the key in a subtree
//parameters: a key to search and the root of the subtree to traverse
//returns: a pointer to the node containing the key if it exists, null otherwise
BSTNode *BinarySearchTree::lookup(KeyType key, BSTNode *tree) const
{
    //case 1: tree is empty, return nullptr
    if (isEmpty(tree))
        return nullptr;
    //recursive cases, lookup in the appropriate subtree
    else if (key < tree->key)
        return lookup(key, tree->left);
    else if (key > tree->key)
        return lookup(key, tree->right);
    //match found, return pointer to the node
    else
        return tree;
}
//setValue
//purpose: updates the value associated with a key, if it exists
//parameters: a key value pair
//returns: void, updates the value if the key is found in the tree
void BinarySearchTree::setValue(KeyType key, ValueType value)
{
    //find the key in the tree
    BSTNode *nodeToSet = lookup(key);
    //if the key was found, update its value
    if (not (nodeToSet == nullptr))
        nodeToSet->val = value;
    //otherwise report error
    else
        std::cerr << key << " not found.\n";
    return;
}
//min
//purpose: gets the node with the minimum key in the tree
//parameters: none
//returns: a pointer to the node containing the smallest key in the tree, 
//         or null if the tree is empty
BSTNode *BinarySearchTree::min() const
{
    if (isEmpty())
        return nullptr;
    return min(root);
    
}
//min helper function
//purpose: gets the node with the minimum key in a subtree
//parameters: a pointer to the root of a subtree
//returns: a pointer to the node with the smallest key in the subtree
//Notes: assumes that the caller function has checked that the key exists
BSTNode *BinarySearchTree::min(BSTNode *tree) const
{
    //if there isn't a key to the left of the node, return a pointer to the node
    if (isEmpty(tree->left))
        return tree;
    //otherwise return the minimum key in the left subtree
    return min(tree->left);
}
//max
//purpose: gets the node with the maximum key in the tree
//parameters: none
//returns: a pointer to the node containing the greatest key in the tree, 
//         or null if the tree is empty
BSTNode *BinarySearchTree::max() const
{
    if (isEmpty())
        return max(root);
    return nullptr;
}
//max helper function
//purpose: gets the node with the maximum key in a subtree
//parameters: a pointer to the root of a subtree
//returns: a pointer to the node with the greatest key in the subtree
//Notes: assumes that the caller function has checked that the key exists
BSTNode *BinarySearchTree::max(BSTNode *tree) const
{
    if (isEmpty(tree->right))
        return tree;
    return max(tree->right);
}
//print
//purpose: prints the tree starting from the root
//parameters: none
//returns: void, outputs to console
void BinarySearchTree::print() const
{
    print(root);
    std::cout << "\n";
}
//print helper function
//purpose: prints the subtree starting from the input node
//parameters: a pointer to the root of the subtree
//returns: void, outputs to console
void BinarySearchTree::print(BSTNode *nodep) const
{
    if (not isEmpty(nodep))
    {
        std::cout << "Key: " << nodep->key << " Value: " << nodep->val << " Count: " << nodep->count << "\n";
        print(nodep->left);
        print(nodep->right);
    }
}
//isLeaf
//purpose: checks if a node is a leaf
//parameters: a node to check
//returns: true if the node is a leaf, false otherwise
bool BinarySearchTree::isLeaf(BSTNode *nodep) const
{
    return not isEmpty(nodep) and nodep->left == nullptr and nodep->right == nullptr;
}
//hasOnlyLeftChild
//purpose: checks if a node only has a left child
//parameters: a node to check
//returns: true if the node has no right child, false otherwise
bool BinarySearchTree::hasOnlyLeftChild(BSTNode *nodep) const
{
    return nodep->right == nullptr;
}
//hasOnlyRightChild
//purpose: checks if a node only has a right child
//parameters: a node to check
//returns: true if the node has no left child, false otherwise
bool BinarySearchTree::hasOnlyRightChild(BSTNode *nodep) const
{
    return nodep->left == nullptr;
}
