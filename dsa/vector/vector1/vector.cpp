#include "vector.h"
#include <assert.h>
#include <iostream>
#include <utility>  // std::swap

Vector::Vector(int size): m_size(size)
    {
        if(size < 0){
            m_size = 1;
        }
        capacity = m_size + 10;
        p_arr = new int[capacity]{}; // the actual size array will be bigger than needed
    }

Vector::Vector(std::string word): m_word(word)
    {

        m_size = m_word.size();

        capacity = m_size + 10;
        p_charArr = new char[capacity]{}; // the actual size array will be bigger than needed
        //if method is not virtual we can call in constructor class
        set(m_word);
    }

Vector::~Vector()
    {
        delete[] p_arr;
        p_arr = nullptr;

        delete[] p_charArr;
        p_charArr = nullptr;
    }

int Vector::get(int idx){
    assert(0 <= idx && idx < m_size);
    return p_arr[idx];
}

void Vector::set(int idx, int val){
    //if assert condition is evaluate to false it stop execution
    assert(0 <= idx && idx < m_size);
    p_arr[idx] = val;
}

void Vector::set(const std::string &s){

    int idx = 0;
    //if assert condition is evaluate to false it stop execution
    assert(0 <= idx && idx < m_size);

    for (char const &c: s) {
        p_charArr[idx] = c;
        idx++;
    }
}

void Vector::print(){
    for(int i = 0; i < m_size; i++){
        std::cout << p_arr[i] << " ";
        std::cout << std::endl;
    }
}

void Vector::cprint(){
    for(int i = 0; i < m_size; i++){
        std::cout << p_charArr[i] << " ";
        //std::cout << std::endl;
    }
}

void Vector::reverse(){

    int j = 1;
    char tmp = ' ';

    for(int i = 0; i <= m_size - j; i++){
        tmp = p_charArr[m_size - j];
        p_charArr[m_size - j] = p_charArr[i];
        p_charArr[i] = tmp;
        j++;
    }
}
int Vector::find(int value){
    for(int i = 0; i < m_size; i++){
        if(p_arr[i] == value)
            return i;
    }

    return -1; // -1 for not found
}

int Vector::getFront(){
    return p_arr[0];
}

int Vector::getBack(){
    return p_arr[m_size - 1];
}

//Add element at the end of the vector
void Vector::pushBack(int value){

    if(m_size == capacity)
        expandCapacity();

    // espace memoire allouée est largement superieur, mais espace effectif vas ajouter un element au n - 1 et occuper n espace
    p_arr[m_size++] = value;

    /*
    // old commentaries :
    //Add element to the end of the vector
    // 1) create a new array of bigger size
    int *arr2 = new int[m_size + 1];

    // 2) copy old data
    //++i increments i and evaluates to the new value of i.

    i++ evaluates to the old value of i, and increments i.

    The reason this doesn't matter in a for loop is that the flow of control works roughly like this:

    1) test the condition
    2) if it is false, terminate
    3) if it is true, execute the body
    4) execute the incrementation step
    Because (1) and (4) are decoupled, either pre- or post-increment can be used.*/
    //for(int i = 0; i < m_size; ++i){
    //    arr2[i] = p_arr[i];
    //}

    // 3) add the new element and increase size
    /*
    int size = 5;
    int* arr1 = new int[size + 1];  // Allocates memory for 6 integers
    int* arr2 = new int[size++];    // Allocates memory for 5 integers, then increments size to 6

    delete[] arr1;
    delete[] arr2;*/
    //arr2[m_size++] = value;

    // 4) change the pointer
    //std::swap(p_arr, arr2);

    // 5) remove useless data
    //delete[] arr2;
}

int Vector::getSizeArray(){
    return m_size;
}

void Vector::expandCapacity(){
    //Double the actual array size
    capacity = capacity * 2;

    std::cout << "Expand capacity to " << capacity << std::endl;

    int *arr2 = new int[capacity];

    for(int i = 0; i < m_size; ++i){
        arr2[i] = p_arr[i]; //copy data
    }

    // 4) change the pointer
    std::swap(p_arr, arr2);

    // 5) remove useless data
    delete[] arr2;
}

void Vector::insert(int idx, int value){
    assert(0 <= idx && idx < m_size);

    //we can t ad any more
    if(m_size == capacity)
        expandCapacity();

    //shit all the data to right first
    for(int i = m_size - 1; i >= idx; --i){
        p_arr[i + 1] = p_arr[i]; //copy data
    }
    // espace memoire allouée est largement superieur, mais espace effectif vas ajouter un element au n - 1 et occuper n espace
    p_arr[idx] = value;
    ++m_size;

    //common mistake to iterate from begin to end, on perd valeur qui sera remplace par valeur du voisin qui sera dupliquee
}
//remove ele
int Vector::pop(int idx){
    assert(0 <= idx && idx < m_size);

    int removeValue =  p_arr[idx];

    //shit all the data to right first
    for(int i = idx + 1; i < m_size; ++i){
        p_arr[i - 1] = p_arr[i]; //copy data
    }

    set(m_size -1, 0);
    --m_size;

    return removeValue;
}

void Vector::rightRotate(){

    int lastItem = getBack();

    //example : 01234 to 40123

    //shit all the data to right first
    for(int i = m_size - 2; i >= 0; --i){
        p_arr[i + 1] = p_arr[i]; //copy data
    }

    p_arr[0] = lastItem;
}

void Vector::rightRotate(int times){

    if(times < 2000000000 && times > 0){
        int lastItem = getBack();

        //example : 01234 to 40123

        while(times > 0){
            //shit all the data to right first
            for(int i = m_size - 2; i >= 0; --i){
                p_arr[i + 1] = p_arr[i]; //copy data
            }

            p_arr[0] = lastItem;
            lastItem = getBack();
            times--;
        }
    }
}

void Vector::leftRotate(){

    int firstItem = getFront();

    //example : 01234 to 12340

    //shit all the data to left first
    for(int i = 1; i < m_size; ++i){
        p_arr[i - 1] = p_arr[i]; //copy data
    }

    p_arr[m_size - 1] = firstItem;
}
//at each time value in found move one step to the left, return the first index where the value is
int Vector::findTransposition(int value){

    int valueCounter = 0, foundPos = -1, tmp = 0;
    bool notFind = true;

    for(int i = 0; i < m_size; i++){
        if(p_arr[i] == value){
            valueCounter++;
            if(i != 0){
                tmp = p_arr[i - 1];
                p_arr[i - 1] = p_arr[i];
                p_arr[i] = tmp;
                foundPos = i;
            }
        }
    }

    for(int i = 0; i < m_size; i++){
        if(p_arr[i] == value && notFind){
            foundPos = i;
            notFind = false;
        }
    }

    return foundPos;
}
