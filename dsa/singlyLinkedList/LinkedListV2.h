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
        Node* getTail() const;
        int getLength() const;
        void setLength(int value);
        void delete_end();
        void delete_front();
        void delete_nth(int index);
        void delete_value(int value);
        Node* get_nth(int n) const;

    protected:

    private:
        Node* head {};
        int length = 0;
};

#endif // LINKEDLISTV2_H
