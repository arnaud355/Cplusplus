#ifndef struct_H
#define struct_H

struct Node {
    int m_data = 0;
    Node* next {};
    Node* prev {};
    //Pointer to the same type
    Node(int data) : m_data(data){}
};

class LinkedList {
    public:
        LinkedList();
        LinkedList();
        ~LinkedList();
        void print();
        void insert_end(int value);
    private:
        Node* head {};
        Node* tail {};
};

void print1(Node* head);

Node* printNodeF(Node* head);

Node* printNodeFReversed(Node* tail);

void print3(Node* head);

int find(Node* startNode, int value);

#endif
