CXX      = clang++
CXXFLAGS = -Wall -Wextra -Wreturn-type -std=c++11 -g
LDFLAGS  = -g 

BST_tests: BST_tests.o BinarySearchTree.o
	${CXX} ${CXXFLAGS} -o BST_tests BinarySearchTree.o BST_tests.o

BST_tests.o: BST_tests.cpp BinarySearchTree.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h





clean:
	rm -rf BST_tests *.o *.dSYM