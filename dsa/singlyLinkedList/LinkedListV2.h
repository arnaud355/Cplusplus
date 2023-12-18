#ifndef LINKEDLISTV2_H
#define LINKEDLISTV2_H
#include "struct.h"

//LinkedList without head
class LinkedListV2
{
    public:
        LinkedListV2();
        ~LinkedListV2();
        void print();
        void addElement(int value);
        Node* getTail();

    protected:

    private:
        Node* head {};
};

#endif // LINKEDLISTV2_H
