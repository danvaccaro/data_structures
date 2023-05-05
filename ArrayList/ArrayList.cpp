#include "ArrayList.h"

//ArrayList
//Purpose: Default constructor - initializes an empty ArrayList
//Parameters: None
//Returns: None
ArrayList::ArrayList() :
    capacity(10), numItems(0), data(new ElemType[capacity]) 
    {}

//~ArrayList
//Purpose: Destructor - frees the memory associated with an ArrayList
//Parameters: None
//Returns: None
ArrayList::~ArrayList() {
    delete[] data;
    data = nullptr;
}