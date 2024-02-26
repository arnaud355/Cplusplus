#include "Stack.h"
#include <assert.h>

Stack::Stack(int sizeStack): m_sizeStack(sizeStack), top(-1)
{
    //ctor
    arrayInt = new int[m_sizeStack];
}

Stack::~Stack()
{
    //dtor
     for (int i = 0; i < m_sizeStack; ++i) {
        delete arrayInt[i];
    }
}

void Stack::push(int value){
    assert(!isFull());
    // why ++top : initialy top is at -1, I would like add my first element at ++ top, it will make zero
    arrayInt[++top] = value;
    /*
        In C++, both ++i and i++ increment the value of i by 1. However, there is a subtle difference between them:

        ++i (pre-increment): It increments the value of i and then returns the incremented value.
        i++ (post-increment): It returns the current value of i, and then increments i.
        In most cases, the difference is negligible, especially when used in simple for loops like the one
        in the example provided.
        Both ++i and i++ would work interchangeably in such cases.

        However, the choice between ++i and i++ can matter in certain scenarios:

        Pre-increment (++i): Use ++i when you want to increment the value of i before using its updated value
        in the current expression.

        int i = 0;
        int j = ++i; // j is assigned the value of i after it's been incremented

        Post-increment (i++): Use i++ when you want to use the current value of i in the current expression
        and then increment it afterward.

        int i = 0;
        int j = i++; // j is assigned the initial value of i, then i is incremented

        So, in the case of the for loop used in the example, ++i and i++ would produce the same result because
        the increment operation is the only operation in each iteration, and there's no difference between
        pre-increment and post-increment in that context. However, some programmers prefer ++i out of habit or
        for performance reasons, as it can sometimes be marginally faster due to avoiding the creation of a temporary
        variable to hold the original value of i.
    */
}

void Stack::pop(){
    assert(!isEmpty());
    return arrayInt[top--];
}

int Stack::peek(){
    assert(!isEmpty());
    return arrayInt[top];
}


bool Stack::isFull(){
    for (int i = 0; i < m_sizeStack; ++i) {
        if(arrayInt[i] == nullptr){
            return 0;
        }
    }

    return 1;
}


bool Stack::isEmpty(){
    for (int i = 0; i < m_sizeStack; ++i) {
        if(arrayInt[i] != nullptr){
            return 0;
        }
    }

    return 1;
}

/*
void Stack::push(int value){
    Node* newNode = new Node(value);
    this->setValueCounter(1);
    if(this->getValueCounter() <= m_sizeStack){
        if(head == nullptr){
            head = tail = newNode;
            head->next = nullptr;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
}

void Stack::pop(){
    Node* nodeToDelete = head;
    head = head->next;

    delete nodeToDelete;
    this->setValueCounter(-1);
}

int Stack::peek(){
    if(head != nullptr)
        return head->m_data;
}

bool Stack::isFull(){
    if(this->getValueCounter() == this->getSize()){
        return 1;
    }

    return 0;
}

void Stack::setValueCounter(int val){
    valueCounter = valueCounter + val;

    if(valueCounter < 0){
        valueCounter = 0;
    }
}

int Stack::getValueCounter(){
    return valueCounter;
}

int Stack::getSize(){
    return m_sizeStack;
}
*/
