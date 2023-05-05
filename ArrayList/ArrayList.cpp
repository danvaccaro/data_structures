#include "ArrayList.h"
#include <iostream>

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

//ArrayList (copy constructor)
//Purpose: Copy constructor - initializes an ArrayList to be a copy of another
//Parameters: const ArrayList &rhs - the ArrayList to be copied
//Returns: None
ArrayList::ArrayList(const ArrayList &rhs) :
    capacity(rhs.capacity), numItems(rhs.numItems), data(new ElemType[capacity]) {
    for (int i = 0; i < numItems; i++) {
        data[i] = rhs.data[i];
    }
}

//operator=
//Purpose: Assignment operator - assigns one ArrayList to be a copy of another
//Parameters: const ArrayList &rhs - the ArrayList to be copied
//Returns: ArrayList - the newly assigned ArrayList
ArrayList ArrayList::operator=(const ArrayList &rhs) {
    if (this != &rhs) {
        delete[] data;
        capacity = rhs.capacity;
        numItems = rhs.numItems;
        data = new ElemType[capacity];
        for (int i = 0; i < numItems; i++) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

bool ArrayList::isEmpty() const {
    return numItems == 0;
}

int ArrayList::getSize() const {
    return numItems;
}

bool ArrayList::contains(ElemType elt) const {
    for (int i = 0; i < numItems; i++) {
        if (data[i] == elt) {
            return true;
        }
    }
    return false;
}
void ArrayList::insert(ElemType elt) {
    if (numItems == capacity) {
        expandCapacity();
    }
    data[numItems] = elt;
    numItems++;
}

void ArrayList::remove(ElemType elt) {
    int index = -1;
    for (int i = 0; i < numItems; i++) {
        if (data[i] == elt) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < numItems - 1; i++) {
            data[i] = data[i + 1];
        }
        numItems--;
    }
}

void ArrayList::setValue(int index, ElemType elt) {
    if (index >= 0 && index < numItems) {
        data[index] = elt;
    }
}

ElemType ArrayList::min() const {
    if (numItems == 0) {
        return 0;
    }
    ElemType min = data[0];
    for (int i = 1; i < numItems; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

ElemType ArrayList::max() const {
    if (numItems == 0) {
        return 0;
    }
    ElemType max = data[0];
    for (int i = 1; i < numItems; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

void ArrayList::print() const {
    std::cout << "[";
    for (int i = 0; i < numItems; i++) {
        std::cout << data[i];
        if (i != numItems - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void ArrayList::expandCapacity() {
    capacity *= 2;
    ElemType *newData = new ElemType[capacity];
    for (int i = 0; i < numItems; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void ArrayList::pushToBack(ElemType elt) {
    if (numItems == capacity) {
        expandCapacity();
    }
    data[numItems] = elt;
    numItems++;
}

void ArrayList::pushToFront(ElemType elt) {
    if (numItems == capacity) {
        expandCapacity();
    }
    for (int i = numItems; i > 0; i--) {
        data[i] = data[i - 1];
    }
    data[0] = elt;
    numItems++;
}

void ArrayList::popFromBack() {
    if (numItems > 0) {
        numItems--;
    }
}

void ArrayList::popFromFront() {
    if (numItems > 0) {
        for (int i = 0; i < numItems - 1; i++) {
            data[i] = data[i + 1];
        }
        numItems--;
    }
}

void ArrayList::clear() {
    numItems = 0;
}

int ArrayList::indexOf(const ElemType elt) const {
    for (int i = 0; i < numItems; i++) {
        if (data[i] == elt) {
            return i;
        }
    }
    return -1;
}

ElemType ArrayList::elementAt(int index) const {
    if (index >= 0 && index < numItems) {
        return data[index];
    }
    return 0;
}