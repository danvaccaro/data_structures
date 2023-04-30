CXX      = clang++
CXXFLAGS = -Wall -Wextra -Wreturn-type -std=c++11 -g
LDFLAGS  = -g 

AVL_tests: AVL_tests.o AVLTree.o
	${CXX} ${CXXFLAGS} -o AVL_tests AVLTree.o AVL_tests.o

AVL_tests.o: AVL_tests.cpp AVLTree.h

AVLTree.o: AVLTree.cpp AVLTree.h





clean:
	rm -rf BST_tests *.o *.dSYM