#ifndef ARRAYLINKEDLIST_H
#define ARRAYLINKEDLIST_H
#include "DoubleLinkedList.h"

class ArrayLinkedList
{
    public:
        ArrayLinkedList();
        ArrayLinkedList(int length);
        ~ArrayLinkedList();
        void setValue(int value, int pos);
        void initValue(int value);
        void printArray();
        void printArrayNonZero();
        Node* getHead() const;
        Node* getTail() const;
        int getLength() const;
        void setLength(int value);
        Node* getNth(int n) const;
        int getValue(int idx) const;
        void addition(ArrayLinkedList& other);
        int getIdx(Node* nodeOfIdx) const;

    protected:

    private:
        Node* head {};
        Node* tail {};
        int m_length = 0;
};

#endif // ARRAYLINKEDLIST_H
