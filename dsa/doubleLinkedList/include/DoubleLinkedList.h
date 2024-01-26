#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <vector>

#include <cassert>
#include <climits>

#include <algorithm>
#include <sstream>

//the head prev need to point to nullptr, like the tail next need to point to nullptr
// head : prev : nullptr <-     ; tail : next -> nullptr
struct Node {
    int m_data = 0;
    Node* next {};
    Node* prev {};
    //Pointer to the same type
    Node(int data) : m_data(data){}

    void set(Node* next, Node* prev){
        this->next = next;
        this->prev = prev;
    }
    ~Node() {
        std::cout << "Destroy value : " << m_data << " at address " << this << std::endl;
    }
};

class DoubleLinkedList
{
    public:

        DoubleLinkedList();
        ~DoubleLinkedList();
        //DoubleLinkedList(const DoubleLinkedList&);
        //DoubleLinkedList &operator=(const DoubleLinkedList &another);
        void print();
        Node* get_nth(int n) const;
        Node* getHead() const;
        Node* getTail() const;
        int getLength () const;
        int getData(int idx) const;
        void printReversed();
        void addNode(Node* node);
        void insertEnd(int value);
        void link(Node* first, Node* second);
        void insertFront(int value);
        void embedAfter(Node* node_before, int value);
        void insertSorted(int value);
        void deleteNode(Node* node);
        void delete_front();
        void delete_end();
        Node* delete_and_link(Node* cur);
        void delete_node_with_key(int value);
        void deleteAllNodesWithKey(int value);
        void delete_nth(int index);
        void deleteEvenPositions();
        void deleteOddPositions();
        bool isPalindrome();
        int findMiddle();
        void swapForwardWithBackward(int k);
        void reverseAllNodesAddresses();
        void merge2SortedLists(DoubleLinkedList& other);
        void debug_print_address();
        void debug_print_node(Node* node, bool is_seperate);
        void debug_print_list(std::string msg);
        std::string debug_to_string();
        void debug_verify_data_integrity();
        void test1();
        void test2();
        void test3();
        void test4();

    protected:

    private:
        Node* head {};
        Node* tail {};
        std::vector<Node*> m_debug_data;
        int length = 0;

        std::vector<Node*> debug_data;	// add/remove nodes you use

        void debug_add_node(Node* node);
        void debug_remove_node(Node* node);

};

#endif // DOUBLELINKEDLIST_H
