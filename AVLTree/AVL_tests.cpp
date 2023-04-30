#include "AVLTree.h"

int main()
{

    std::cerr << "Empty tree Tests:\n";
    BinarySearchTree emptyBSTree;
    emptyBSTree.remove(5);
    emptyBSTree.print();

    std::cerr << "Single node tree tests: \n";
    BinarySearchTree singleNodeBSTree;
    singleNodeBSTree.insert(50, "insertion1");
    singleNodeBSTree.print();
    singleNodeBSTree.remove(5);
    singleNodeBSTree.remove(50);
    singleNodeBSTree.print();

    std::cerr << "Three node chevron tree tests: \n";
    BinarySearchTree threeNodeChevronBSTree;

    threeNodeChevronBSTree.insert(50, "insertion1");
    threeNodeChevronBSTree.insert(25, "insertion2");
    threeNodeChevronBSTree.insert(75, "insertion3");
    threeNodeChevronBSTree.print();
    threeNodeChevronBSTree.remove(5);
    threeNodeChevronBSTree.remove(50);
    threeNodeChevronBSTree.print();
    threeNodeChevronBSTree.remove(25);
    threeNodeChevronBSTree.print();

    std::cerr << "Balanced tree tests: \n";
    BinarySearchTree balancedBSTree;
    balancedBSTree.insert(50, "insertion1");
    balancedBSTree.insert(25, "insertion2");
    balancedBSTree.insert(75, "insertion3");
    balancedBSTree.insert(60, "insertion4");
    balancedBSTree.insert(100, "insertion5");
    balancedBSTree.insert(18, "insertion6");
    balancedBSTree.insert(12, "insertion7");
    balancedBSTree.insert(22, "insertion8");
    balancedBSTree.insert(33, "insertion9");
    balancedBSTree.insert(40, "insertion10");

    balancedBSTree.print();

    return 0;
}