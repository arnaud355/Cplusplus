#ifndef LINKEDLISTV2_H
#define LINKEDLISTV2_H
#include "struct.h"

//Single LinkedList, without prev in insert functions
//LinkedList without head
class LinkedListV2
{
    public:
        LinkedListV2();
        ~LinkedListV2();
        void print();
        void addElement(int value);
        //insertElement manage also insertion for the first and last node
        void insertElement(int value, int pos);
        Node* getTail() const;
        Node* getHead() const;
        int getLength() const;
        void setLength(int value);
        void delete_end();
        void delete_front();
        void delete_nth(int index);
        void delete_value(int value);
        Node* get_nth(int n) const;
        void delete_node_with_key(int value);
        void swap_pairs();
        void printNodesAddresses();
        void reverseListNodes();
        void deleteEvenPos();
        void insertSorted(int value);
        void swapHeadAndTail();
        void leftRotate(int k);
        void removeDuplicates();
        void removeLastOccurence(int key);
        void moveBack(int key);
        //int maxValue();
        //int maxValue(Node* head, bool firstCall);
        int maxValue(Node* head);
        void arrangeOddAndEven();
        void insertAlternate(const LinkedListV2& other);
        void addNumber(const LinkedListV2& other);
        void changeValueOfNode(int value, int idx);
        void removeAllRepeated();
        int getValueFromNode(int value);
        void replaceValueOfNode(int value, int idx);
        int getData(int idx) const;
        void purgeListNodeFromTo(int idxStart, int idxEnd);
        void reverseChain(int k);

    protected:

    private:
        Node* head {};
        Node* tail {};
        int length = 0;
};

#endif // LINKEDLISTV2_H
