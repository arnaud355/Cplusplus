#ifndef struct_H
#define struct_H

struct Node {
    int m_data = 0;
    Node* next {};
    Node* prev {};
    //Pointer to the same type
    Node(int data) : m_data(data){}
    ~Node() {
        cout << "Destroy value : " << data << " at address " << this << std::endl;
    }
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void print();
        void insert_end(int value);
        void insert_value(int value, int pos);
        void delete_end();
        Node* getHead();
        Node* getTail();
        int getLength();
        Node* get_nth(int n);
        int searchItem(int value);
        int searchItemImproved(int value);
        void debugVerifyDataIntegrety();
        std::string debugToString();
    private:
        Node* head {};
        Node* tail {};
        int length = 0;
};

void print1(Node* head);

void reversePrint1(Node* tail);

Node* printNodeF(Node* head);

Node* printNodeFReversed(Node* tail);

void print3(Node* head);

int find(Node* startNode, int value);

#endif
