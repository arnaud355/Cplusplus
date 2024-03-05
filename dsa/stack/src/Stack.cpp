#include "Stack.h"
#include <assert.h>

Stack::Stack(int sizeStack): m_sizeStack(sizeStack), added_elements(-1)
{
    //ctor
    arrayInt = new int[m_sizeStack];
}

Stack::Stack(int sizeStack, char letter): m_sizeStack(sizeStack),m_letter(letter), added_elements(-1)
{
    //ctor
    arrayChar = new char[m_sizeStack];
}

Stack::~Stack()
{
    //dtor
    delete[] arrayInt;
    delete[] arrayChar;
}

void Stack::push(int value){
    assert(!isFull());
    // why ++added_elements : initialy added_elements is at -1, I would like add my first element at ++ added_elements, it will make zero
    arrayInt[++added_elements] = value;

    //or for educational context
    /*
    if(isFull()){
        std::cout << "full stack" << std::endl;
    }
    else{
        arrayInt[++added_elements] = value;
    }

    */
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

void Stack::push(char value){
    assert(!isFull());
    arrayChar[++added_elements] = value;
}

int Stack::pop(){
    assert(!isEmpty());
    return arrayInt[added_elements--];
}

void Stack::popL(){
    assert(!isEmpty());
    arrayChar[added_elements--];
}

int Stack::peek(){
    assert(!isEmpty());
    return arrayInt[added_elements];
}


bool Stack::isFull(){
    return added_elements == m_sizeStack - 1;
}


bool Stack::isEmpty(){
    return added_elements == - 1;
}

void Stack::display(){
    for (int i = 0; i <= added_elements; i++) {
        std::cout << arrayInt[i] << std::endl;
    }
}

void Stack::displayL(){
    for (int i = 0; i <= added_elements; i++) {
        std::cout << arrayChar[i] << std::endl;
    }
}

int Stack::getValue(int idx){
    if(idx <= added_elements){
        return arrayInt[idx];
    }

    return -1;
}

std::string Stack::reverseSubwords(std::string line){
    Stack stkWords(line.length(),'a');
    int counter = 0;

    for (size_t i = 0; i < line.length(); ++i) {
        //std::cout << line[i] << std::endl;
        stkWords.push(line[i]);
        if(line[i] == ' '){
            counter++;
        }
    }

    Stack stk(counter);


    for (int i = 0; i < line.length(); i++) {
        //std::cout << line[i] << std::endl;
        if(line[i] == ' '){
            stk.push(i);
        }
    }

    //stk.display();
    int v = 0;
    int j = 0;
    int start = 0;
    char temp = ' ';

    while(v < counter){

        j = stk.getValue(v);

        for(int i = start; i < j; i++){
            temp = line[i];
            line[i] = line[j - 1];
            line[j - 1] = temp;
            j--;
        }

        start = stk.getValue(v);
        v++;
    }

    return line;
}

std::vector<int> Stack::intToArray(int num){
    std::vector<int> digits;

    // Handle the case of negative numbers
    if (num < 0) {
        std::cout << "No management of negative number" << std::endl;
    } else if (num == 0) {
        digits.push_back(0); // Special case for 0
        return digits;
    }

    // Extract digits one by one and store in the vector
    while (num > 0) {
        digits.insert(digits.end(), num % 10);
        num /= 10;
    }

    return digits;
}
//1234 => 4321
int Stack::reverseNum(int value){

    std::vector<int> arrayInt = intToArray(value);
    std::string numberS = " ";

    for (int digit : arrayInt) {
        //std::cout << " " << digit;
        numberS += digit;
    }
    //int number =  std::stoi(numberS);

    return value;
}

bool Stack::isValid(std::string str){
    int j = str.length() - 1;
    bool valid = true;
    int sizeStr = str.length() / 2;

    for(int i = 0; i < sizeStr; i++){
            switch(str[i]) {
                case '(':
                    if(str[j] != ')')
                        valid = false;
                    break;
                case '[':
                    if(str[j] != ']')
                        valid = false;
                    break;
                case '{':
                    if(str[j] != '}')
                        valid = false;
                    break;
                  default:
                    std::cout << "No expected character" << std::endl;
            }
            j--;
    }

    return valid;
}
//remove duplicate letter if adjacent, example : abbaca => aaca => ca
void Stack::removeDuplicates(std::string s){
    Stack stk(s.length(),'a');
    int v = 1;

    for(int i = 0; i < s.length(); i++){
        stk.push(s[i]);
    }

    //stk.displayL();

    for(int i = 0; i < s.length(); i++){
        for(int j = v; j < s.length(); j++){

        }
        v++;
    }
    stk.popL();

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
