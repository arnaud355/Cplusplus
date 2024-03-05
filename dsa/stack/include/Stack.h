#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>

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
        Stack(int sizeStack, char letter);
        ~Stack();
        void push(int value);
        void push(char value);
        int pop();
        void popL();
        int peek();
        bool isFull();
        bool isEmpty();
        void display();
        void displayL();
        std::string reverseSubwords(std::string line);
        int getValue(int idx);
        int reverseNum(int value);
        std::vector<int> intToArray(int num);
        bool isValid(std::string str);
        void removeDuplicates(std::string s);
        //void setValueCounter(int val);
        //int getValueCounter();
        //int getSize();

    protected:

    private:
        //Node* head {};
        //Node* tail {};
        int* arrayInt {};
        char* arrayChar {};
        int m_sizeStack = 0;
        char m_letter = ' ';
        int added_elements {};
        //int valueCounter = 0;
};

#endif // STACK_H
