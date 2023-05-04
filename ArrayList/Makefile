CXX = clang++
CXXFLAGS = -Wall -Wextra -Wreturn-type -std=c++11 -g
LDFLAGS = -g

ArrayList_tests: ArrayList_tests.o ArrayList.o
	${CXX} ${CXXFLAGS} -o ArrayList_tests ArrayList.o ArrayList_tests.o

ArrayList_tests.o: ArrayList_tests.cpp ArrayList.h

ArrayList.o: ArrayList.cpp ArrayList.h

clean:
	rm -rf ArrayList_tests *.o *.dSYM