#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {

    public:
        Vector();
        Vector(int size);
        Vector(std::string name);
        ~Vector();

        int get(int idx);

        void set(int idx, int val);

        void print();

        int find(int value);

        int getFront();

        int getBack();

        void pushBack(int value);

        int getSizeArray();

        void insert(int idx, int value);

        int pop(int idx);

        void rightRotate();

        void rightRotate(int times);

        void leftRotate();

        int findTransposition(int value);

        void cprint();

        void set(const std::string &s);

        void reverse();

    private:
        int *p_arr = nullptr;
        char *p_charArr = nullptr;
        int m_size = 0; //user size
        int capacity = 0; //actual size
        std::string m_word = "";
        void expandCapacity(); //method en privee, utilisateur ne doit pas pouvoir y acceder
};
#endif
