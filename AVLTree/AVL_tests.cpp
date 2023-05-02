#include "AVLTree.h"

int main()
{
    AVLTree testAVLTree;
    testAVLTree.insert(2, "inserted1");
    testAVLTree.insert(3, "inserted2");
    testAVLTree.insert(1, "inserted3");
    testAVLTree.insert(5, "inserted4");
    testAVLTree.insert(9, "inserted5");
    testAVLTree.print();
    testAVLTree.remove(3);
    testAVLTree.print();
    /*
        std::cerr << "Single node tree tests: \n";
        AVLTree singleNodeAVLTree;
        singleNodeAVLTree.insert(50, "insertion1");
        singleNodeAVLTree.print();
        singleNodeAVLTree.remove(5);
        singleNodeAVLTree.remove(50);
        singleNodeAVLTree.print();
        std::cerr << "Three node chevron tree tests: \n";
        AVLTree threeNodeChevronAVLTree;

        threeNodeChevronAVLTree.insert(50, "insertion1");
        threeNodeChevronAVLTree.insert(25, "insertion2");
        threeNodeChevronAVLTree.insert(75, "insertion3");
        threeNodeChevronAVLTree.print();
        threeNodeChevronAVLTree.remove(5);
        threeNodeChevronAVLTree.remove(50);
        threeNodeChevronAVLTree.print();
        threeNodeChevronAVLTree.remove(25);
        threeNodeChevronAVLTree.print();

        std::cerr << "Balanced tree tests: \n";
        AVLTree balancedAVLTree;
        balancedAVLTree.insert(50, "insertion1");
        balancedAVLTree.insert(25, "insertion2");
        balancedAVLTree.insert(75, "insertion3");
        balancedAVLTree.insert(60, "insertion4");
        balancedAVLTree.insert(100, "insertion5");
        balancedAVLTree.insert(18, "insertion6");
        balancedAVLTree.insert(12, "insertion7");
        balancedAVLTree.insert(22, "insertion8");
        balancedAVLTree.insert(33, "insertion9");
        balancedAVLTree.insert(40, "insertion10");

        balancedAVLTree.print();
        */

    return 0;
}