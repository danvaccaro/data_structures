#ifndef ARRAYLIST_H
#define ARRAYLIST_H

using ElemType = int;

class ArrayList {
public:
    //constructor
    ArrayList();
    //destructor
    ~ArrayList();
    //copy constructor
    ArrayList(const ArrayList &rhs);
    //assignment operator
    ArrayList operator=(const ArrayList &rhs);
    //check if the list is empty
    bool isEmpty() const;
    //get the size of the list
    int getSize() const;
    //check if the list contains the given element
    bool contains(ElemType elt) const;
    //insert the given element at the given index
    void insert(int index, ElemType elt);
    //remove the given element from the list
    void remove(ElemType elt);
    //set the value of the element at the given index
    void setValue(int index, ElemType elt);
    //get the minimum value in the list
    ElemType *min() const;
    //get the maximum value in the list
    ElemType *max() const;
    //print the list to the console
    void print() const;
    //push the element to the end of the list
    void pushToBack(ElemType elt);
    //push the element to the front of the list
    void pushToFront(ElemType elt);
    //remove the last element in the list
    void popFromBack();
    //remove the first element in the list
    void popFromFront();
    //empty the list
    void clear();
    //get the index of the given element
    int indexOf(const ElemType elt) const;
    //get the element at the given index
    ElemType *elementAt(int index) const;

private:
    //an array of elements
    ElemType *data;
    //the number of elements in the list
    int numItems;
    //the number of slots in the array
    int capacity;
    //expand the capacity of the array
    void expandCapacity();
};
#endif