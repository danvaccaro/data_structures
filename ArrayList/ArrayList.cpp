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
    //delete the array and set its pointer to null
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
    //if the two lists are the same, return the current list
    //otherwise, free the current list and allocate a new one
    if (this != &rhs) {
        delete[] data;
        //set capacity and size to the same value as the rhs
        capacity = rhs.capacity;
        numItems = rhs.numItems;
        data = new ElemType[capacity];
        //copy each item in the rhs list to the current list
        for (int i = 0; i < numItems; i++) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}
//isEmpty
//Purpose: Checks if the ArrayList is empty
//Parameters: None
//Returns: bool - true if the ArrayList is empty, false otherwise
bool ArrayList::isEmpty() const {
    return numItems == 0;
}
//getSize
//Purpose: Returns the number of items in the ArrayList
//Parameters: None
//Returns: int - the number of items in the ArrayList
int ArrayList::getSize() const {
    return numItems;
}
//contains
//Purpose: Checks if an item is in the ArrayList
//Parameters: ElemType - the item to be checked
//Returns: bool - true if the item is in the ArrayList, false otherwise
bool ArrayList::contains(ElemType elt) const {
    //loop through each item, return true if the item is found
    for (int i = 0; i < numItems; i++) {
        if (data[i] == elt) {
            return true;
        }
    }
    //otherwise return false
    return false;
}
//insert
//Purpose: Inserts an item into the ArrayList at the specified index
//Parameters: int - the index at which to insert, ElemType - the item to be inserted
void ArrayList::insert(int index, ElemType elt) {
    //expand if necessary
    if (numItems == capacity) {
        expandCapacity();
    }
    //move all items after the specified index to the right
    for (int i = index; i < numItems + 1; i++) {
        data[i + 1] = data[i];
    }
    //set the value at the index to the new item
    data[index] = elt;
    //increment the size of the ArrayList
    numItems++;
}
//remove
//Purpose: Removes an element from the ArrayList, if it is present
//Parameters: An element to be removed
//Returns: None - updates the ArrayList
void ArrayList::remove(ElemType elt) {
    //default to invalid index
    int index = -1;
    //loop through each item, return the index if the item is found
    for (int i = 0; i < numItems; i++) {
        if (data[i] == elt) {
            index = i;
            break;
        }
    }
    //if the element was found, shift all items after it to the left
    if (index != -1) {
        for (int i = index; i < numItems - 1; i++) {
            data[i] = data[i + 1];
        }
        //decrement the size of the ArrayList
        numItems--;
    }
}
//setValue
//Purpose: Sets the value of an item at a specified index
//Parameters: int - the index at which to set the value, ElemType - the value to be set
//Returns: None - updates the ArrayList
void ArrayList::setValue(int index, ElemType elt) {
    //if the index is within range, set the value at the index to the new value
    if (index >= 0 && index < numItems) {
        data[index] = elt;
    }
}
//min
//Purpose: Finds the minimum value in the ArrayList
//Parameters: None
//Returns: ElemType* - a pointer to the minimum value in the ArrayList
ElemType *ArrayList::min() const {
    //if the list is empty, return nullptr
    if (numItems == 0) {
        return nullptr;
    }
    //store a pointer to the min value - set it to the first item in the list
    ElemType *min = &data[0];
    //loop through each item, updating the min pointer if a smaller value is found
    for (int i = 1; i < numItems; i++) {
        if (data[i] < *min) {
            min = &data[i];
        }
    }
    //return the min pointer
    return min;
}
//max
//Purpose: Finds the maximum value in the ArrayList
//Parameters: None
//Returns: ElemType* - a pointer to the maximum value in the ArrayList
ElemType *ArrayList::max() const {
    //if the list is empty, return nullptr
    if (numItems == 0) {
        return nullptr;
    }
    //store a pointer to the max value - set it to the first item in the list
    ElemType *max = &data[0];
    //loop through each item, updating the max pointer if a larger value is found
    for (int i = 1; i < numItems; i++) {
        if (data[i] > *max) {
            max = &data[i];
        }
    }
    //return the max value pointer
    return max;
}
//print
//Purpose: Prints the list to the console
//Parameters: None
//Returns: None
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
//expandCapacity
//Purpose: Doubles the capacity of the ArrayList
//Parameters: None
//Returns: None - updates the ArrayList capacity
void ArrayList::expandCapacity() {
    //double the capacity
    capacity *= 2;
    //set up a new array with the new capacity
    ElemType *newData = new ElemType[capacity];
    //copy the data from the old array to the new array up to the number of items
    for (int i = 0; i < numItems; i++) {
        newData[i] = data[i];
    }
    //free old array memory
    delete[] data;
    //set the data pointer to the new array
    data = newData;
}
//pushToBack
//Purpose: Adds an item to the back of the ArrayList
//Parameters: ElemType - the item to be added
//Returns: None - updates the ArrayList by adding the item to the back
void ArrayList::pushToBack(ElemType elt) {
    insert(numItems, elt);
}
//pushToFront
//Purpose: Adds an item to the front of the ArrayList
//Parameters: ElemType - the item to be added
//Returns: None - updates the ArrayList by adding the item to the front
void ArrayList::pushToFront(ElemType elt) {
    insert(0, elt);
}
//popFromBack
//Purpose: Removes the last element from the ArrayList
//Parameters: None
//Returns: None - updates the ArrayList by reducing the size by 1
void ArrayList::popFromBack() {
    if (numItems > 0) {
        numItems--;
    }
}
//popFromFront
//Purpose: Removes the first element from the ArrayList
//Parameters: None
//Returns: None - updates the ArrayList by removing the first element
//         and shifting all other elements to the right
void ArrayList::popFromFront() {
    if (numItems > 0) {
        for (int i = 0; i < numItems - 1; i++) {
            data[i] = data[i + 1];
        }
        numItems--;
    }
}
//clear
//Purpose: Empties the ArrayList
//Parameters: None
//Returns: None - updates the ArrayList by removing 
//         all elements.
void ArrayList::clear() {
    numItems = 0;
}
//indexOf
//Purpose: Finds the index of an element in the ArrayList
//Parameters: ElemType - the element to be found
//Returns: int - the index of the element, or -1 if it is not found
int ArrayList::indexOf(const ElemType elt) const {
    //loop through each item, returning the index if the item is found
    for (int i = 0; i < numItems; i++) {
        if (data[i] == elt) {
            return i;
        }
    }
    //return -1 if the item is not found
    return -1;
}
//ElementAt
//Purpose: Returns a pointer to the element at a specified index
//Parameters: int - the index of the element to be returned
//Returns: ElemType* - a pointer to the element at the specified index
ElemType *ArrayList::elementAt(int index) const {
    //if the index is in range, return a pointer to the element
    if (index >= 0 && index < numItems) {
        return &data[index];
    }
    //else return nullptr
    return nullptr;
}