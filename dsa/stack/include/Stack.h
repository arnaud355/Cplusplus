#ifndef STACK_H
#define STACK_H
#include <iostream>

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
//last in, first out
class Stack
{
    public:
        Stack();
        Stack(int sizeStack);
        ~Stack();
        void push(int value);
        void pop();
        int peek();
        bool isFull();
        bool isEmpty();
        //void setValueCounter(int val);
        //int getValueCounter();
        //int getSize();

    protected:

    private:
        //Node* head {};
        //Node* tail {};
        int top {};
        int* arrayInt {};
        int m_sizeStack = 0;
        //int valueCounter = 0;
};

#endif // STACK_H
