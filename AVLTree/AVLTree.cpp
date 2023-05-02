#include "AVLTree.h"
// default constuctor, empty tree with null root
AVLTree::AVLTree()
{
    root = nullptr;
    size = 0;
}
// destructor deletes the tree starting at the root
AVLTree::~AVLTree()
{
    deleteTree(root);
}
// deleteTree
// Purpose: recursively deallocates memory for each node in the tree rooted at nodep
// Parameters: a pointer to the root AVLNode in the tree
// Returns: void, updates the tree instance
void AVLTree::deleteTree(AVLNode *nodep)
{
    // if the node isn't empty, delete the left and right subtrees and then delete the node
    if (not isEmpty(nodep))
    {
        deleteTree(nodep->right);
        deleteTree(nodep->left);
        delete nodep;
    }
}
// isEmpty
// Purpose: checks if this tree is empty.
// Parameters: none.
// Returns: a bool, true if the root is empty, false otherwise
bool AVLTree::isEmpty() const
{
    return isEmpty(root);
}
// isEmpty helper function
// Purpose: checks if any given subtree is empty
// Parameters: a pointer to a subtree
// Returns: true if the subtree root is null, false otherwise
bool AVLTree::isEmpty(AVLNode *nodep) const
{
    // if the node is nullptr, it is empty
    return nodep == nullptr;
}
// getSize
// Purpose: retrieves the size of the tree.
// Parameters: none
// Returns: an int, the number of nodes in this tree
int AVLTree::getSize() const
{
    return size;
}
// contains
// Purpose: checks if the tree contains a given key
// Parameters: a key to search
// Returns: true if the key is in the tree, false otherwise
bool AVLTree::contains(KeyType searchKey) const
{
    return contains(searchKey, root);
}
// contains helper function
// purpose: checks if a given subtree contains a given key
// parameters: a key to search and a pointer to the root node in the subtree
// returns: true if the key is present, false otherwise
bool AVLTree::contains(KeyType searchKey, AVLNode *tree) const
{
    // case 1: tree is empty
    if (isEmpty(tree))
        return false;
    // recursive cases: utilize AVL invariant and split tree
    else if (searchKey < tree->key)
        return contains(searchKey, tree->left);
    else if (searchKey > tree->key)
        return contains(searchKey, tree->right);
    // otherwise the key was found, return true
    else
        return true;
}
// insert
// purpose: inserts a key value pair into the tree
// parameters: a key and a value
// returns: void, updates the root and size members appropriately
void AVLTree::insert(KeyType key, ValueType value)
{
    root = insert(key, value, root);
    size++;
}
// insert helper function
// purpose: recursively inserts a key-value pair into the subtree starting at a given node
// parameters: a key, a value, and a pointer the the root of the subtree
// returns: a pointer to the root of the subtree
AVLNode *AVLTree::insert(KeyType key, ValueType value, AVLNode *tree)
{
    // case 1: empty tree, create a new node and insert it at the root
    if (isEmpty(tree))
        return new AVLNode(key, value);
    // case 2: key is a duplicate - reduce the count by 1
    else if (key == tree->key)
        tree->count++;
    // recursive case 1: key is less than root's key - insert into the left subtree
    else if (key < tree->key)
        tree->left = insert(key, value, tree->left);
    // recursive case 2: key is greater than root's key - insert into right subtree
    else if (key > tree->key)
        tree->right = insert(key, value, tree->right);
    // Begin AVL maintenance
    // update height
    updateHeight(tree);
    // return the rebalanced tree
    return rebalance(tree);
}
// remove
// purpose: removes the node containing a given key from the tree
// parameters: a key to remove
// returns: void, deletes the node and updates pointers to the deleted node
void AVLTree::remove(KeyType key)
{
    // if the tree contains the key, remove from the tree starting at the root
    if (contains(key))
        root = remove(key, root);
    // otherwise the key isn't in the tree. report to the user
    else
        std::cerr << key << " not found in tree :(\n";
}
// remove helper function
// purpose: removes the node associated with the key from the given subtree
// parameters: a key and the root of a subtree
// returns: a pointer to the root of the updated subtree
AVLNode *AVLTree::remove(KeyType key, AVLNode *tree)
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
    // case 4: the key is equal to the current root's key
    else
    {
        // if it's a duplicate key, reduce the count by 1
        if (tree->count > 1)
            tree->count--;
        // if the node is a leaf, delete the node and update the subtree root to null
        else if (isLeaf(tree))
        {
            delete tree;
            return nullptr;
        }
        // if the node only has a left child, point the new root to the node's left child
        // and free up node memory
        else if (hasOnlyLeftChild(tree))
        {
            AVLNode *newRoot = tree->left;
            delete tree;
            return newRoot;
        }
        // if the node only has a right child, point the new root to the node's right child
        // and free up node memory
        else if (hasOnlyRightChild(tree))
        {
            AVLNode *newRoot = tree->right;
            delete tree;
            return newRoot;
        }
        // else it has two children
        else
        {
            // copy the data from the minimum of the right subtree
            AVLNode *minOfRight = min(tree->right);
            tree->key = minOfRight->key;
            tree->val = minOfRight->val;
            // remove the min from the right subtree
            tree->right = remove(minOfRight->key, tree->right);
        }
    }
    /*AVL Maintenence*/
    updateHeight(tree);
    //return the rebalanced tree
    return rebalance(tree);
}
// lookup
// purpose: looks for a given key in the tree
// parameters: a key to search
// returns: a pointer to the node containing the key if it exists, nullptr otherwise
AVLNode *AVLTree::lookup(KeyType key) const
{
    if (contains(key))
        return lookup(key, root);
    return nullptr;
}
// lookup helper function
// purpose: recursively searches for the key in a subtree
// parameters: a key to search and the root of the subtree to traverse
// returns: a pointer to the node containing the key if it exists, null otherwise
AVLNode *AVLTree::lookup(KeyType key, AVLNode *tree) const
{
    // case 1: tree is empty, return nullptr
    if (isEmpty(tree))
        return nullptr;
    // recursive cases, lookup in the appropriate subtree
    else if (key < tree->key)
        return lookup(key, tree->left);
    else if (key > tree->key)
        return lookup(key, tree->right);
    // match found, return pointer to the node
    else
        return tree;
}
// setValue
// purpose: updates the value associated with a key, if it exists
// parameters: a key value pair
// returns: void, updates the value if the key is found in the tree
void AVLTree::setValue(KeyType key, ValueType value)
{
    // find the key in the tree
    AVLNode *nodeToSet = lookup(key);
    // if the key was found, update its value
    if (not(nodeToSet == nullptr))
        nodeToSet->val = value;
    // otherwise report error
    else
        std::cerr << key << " not found.\n";
    return;
}
// min
// purpose: gets the node with the minimum key in the tree
// parameters: none
// returns: a pointer to the node containing the smallest key in the tree,
//          or null if the tree is empty
AVLNode *AVLTree::min() const
{
    if (isEmpty())
        return nullptr;
    return min(root);
}
// min helper function
// purpose: gets the node with the minimum key in a subtree
// parameters: a pointer to the root of a subtree
// returns: a pointer to the node with the smallest key in the subtree
// Notes: assumes that the caller function has checked that the key exists
AVLNode *AVLTree::min(AVLNode *tree) const
{
    // if there isn't a key to the left of the node, return a pointer to the node
    if (isEmpty(tree->left))
        return tree;
    // otherwise return the minimum key in the left subtree
    return min(tree->left);
}
// max
// purpose: gets the node with the maximum key in the tree
// parameters: none
// returns: a pointer to the node containing the greatest key in the tree,
//          or null if the tree is empty
AVLNode *AVLTree::max() const
{
    if (isEmpty())
        return max(root);
    return nullptr;
}
// max helper function
// purpose: gets the node with the maximum key in a subtree
// parameters: a pointer to the root of a subtree
// returns: a pointer to the node with the greatest key in the subtree
// Notes: assumes that the caller function has checked that the key exists
AVLNode *AVLTree::max(AVLNode *tree) const
{
    if (isEmpty(tree->right))
        return tree;
    return max(tree->right);
}
// print
// purpose: prints the tree starting from the root
// parameters: none
// returns: void, outputs to console
void AVLTree::print() const
{
    print(root);
    std::cout << "\n";
}
// print helper function
// purpose: prints the subtree starting from the input node
// parameters: a pointer to the root of the subtree
// returns: void, outputs to console
void AVLTree::print(AVLNode *nodep) const
{
    if (not isEmpty(nodep))
    {
        std::cout << "Key: " << nodep->key << " Value: " << nodep->val << " Count: " << nodep->count << " Height: " << nodep->height << "\n";
        print(nodep->left);
        print(nodep->right);
    }
}
// isLeaf
// purpose: checks if a node is a leaf
// parameters: a node to check
// returns: true if the node is a leaf, false otherwise
bool AVLTree::isLeaf(AVLNode *nodep) const
{
    return not isEmpty(nodep) and nodep->left == nullptr and nodep->right == nullptr;
}
// hasOnlyLeftChild
// purpose: checks if a node only has a left child
// parameters: a node to check
// returns: true if the node has no right child, false otherwise
bool AVLTree::hasOnlyLeftChild(AVLNode *nodep) const
{
    return nodep->right == nullptr;
}
// hasOnlyRightChild
// purpose: checks if a node only has a right child
// parameters: a node to check
// returns: true if the node has no left child, false otherwise
bool AVLTree::hasOnlyRightChild(AVLNode *nodep) const
{
    return nodep->left == nullptr;
}

int AVLTree::getHeight(AVLNode *nodep) const
{
    if (isEmpty(nodep))
        return -1;
    return nodep->height;
}

int AVLTree::heightDiff(AVLNode *nodep) const
{
    return getHeight(nodep->left) - getHeight(nodep->right);
}

void AVLTree::updateHeight(AVLNode *nodep)
{
    nodep->height = 1 + std::max(getHeight(nodep->left), getHeight(nodep->right));
}

AVLNode *AVLTree::rebalance(AVLNode *nodep)
{
    // if heightdiff is greater than 1, left subtree is too tall
    if (heightDiff(nodep) > 1)
    {
        // left left case
        if (heightDiff(nodep->left) > 0)
        {
            nodep = rotateRight(nodep);
        }
        // left right case
        else
        {
            nodep->left = rotateLeft(nodep->left);
            nodep = rotateRight(nodep);
        }
        // else if heightdiff is less than -1, right subtree is too tall
    }
    else if (heightDiff(nodep) < -1)
    {
        // right right case
        if (heightDiff(nodep->right) < 0)
        {
            nodep = rotateLeft(nodep);
        }
        // right left case
        else
        {
            nodep->right = rotateRight(nodep->right);
            nodep = rotateLeft(nodep);
        }
    }
    return nodep;
}

AVLNode *AVLTree::rotateLeft(AVLNode *nodep)
{
    // store the right subtree
    AVLNode *temp = nodep->right;
    // move the left subtree of the right subtree to the right subtree of the node
    nodep->right = temp->left;
    // move the node to the left subtree of the right subtree
    temp->left = nodep;
    // update the heights of the node and the right subtree
    updateHeight(nodep);
    updateHeight(temp);
    // update the pointer to the node
    nodep = temp;
    return nodep;
}
AVLNode *AVLTree::rotateRight(AVLNode *nodep)
{
    // store the left subtree
    AVLNode *temp = nodep->left;
    // move the right subtree of the left subtree to the left subtree of the node
    nodep->left = temp->right;
    // move the node to the right subtree of the left subtree
    temp->right = nodep;
    // update the heights of the node and the left subtree
    updateHeight(nodep);
    updateHeight(temp);
    // update the pointer to the node
    nodep = temp;
    return nodep;
}