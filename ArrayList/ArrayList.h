#ifndef ARRAYLIST_H
#define ARRAYLIST_H

using ElemType = int;

class ArrayList {
public:
    //constructor
    ArrayList();
    //destructor
    ~ArrayList();
    ArrayList(const ArrayList &rhs);
    ArrayList operator=(const ArrayList &rhs);
    bool isEmpty() const;
    int getSize() const;
    bool contains(ElemType elt) const;
    void insert(ElemType elt);
    void remove(ElemType elt);
    void setValue(ElemType elt);
    ElemType min() const;
    ElemType max() const;
    void print() const;

public:
    ElemType *data;
    int size;
};
#endif