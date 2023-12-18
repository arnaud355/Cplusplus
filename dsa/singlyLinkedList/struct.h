#ifndef struct_H
#define struct_H
#include <iostream>
#include <vector>

struct Node {
    int m_data = 0;
    Node* next {};
    Node* prev {};
    //Pointer to the same type
    Node(int data) : m_data(data){}
    ~Node() {
        std::cout << "Destroy value : " << m_data << " at address " << this << std::endl;
    }
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void print();
        void insert_end(int value);
        void insert_front(int value);
        void insert_value(int value, int pos);
        void delete_end();
        void delete_front();
        Node* getHead() const;
        Node* getTail() const;
        int getLength() const;
        Node* get_nth(int n);
        Node* get_nth_back(int n);
        int searchItem(int value);
        int searchItemImproved(int value);
        bool isSame(const LinkedList& other);
        bool isSameAndLength(const LinkedList& other);
        //void debugVerifyDataIntegrety();
        //std::string debugToString();
        //void debugPrintNode(Node* node, bool isSeparate);
        //void debugPrintList(std::string msg);
        //void debug_add_node(Node* node);
        //void debug_remove_node(Node* node);
    private:
        Node* head {};
        Node* tail {};
        //std::vector<Node*> m_debug_data;
        int length = 0;
};

void print1(Node* head);

void reversePrint1(Node* tail);

Node* printNodeF(Node* head);

Node* printNodeFReversed(Node* tail);

void print3(Node* head);

int find(Node* startNode, int value);

//void test1();

//void debug_add_node(Node* node);

//void debug_remove_node(Node* node);

#endif
