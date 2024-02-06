#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "DoubleLinkedList.h"

struct ColumnNode {
    int m_data = 0;
    int m_column{};
    ColumnNode* next {};
    ColumnNode* prev {};

    ColumnNode(int data, int column) : m_data(data), m_column(column){}

    ~ColumnNode() {
        std::cout << "Destroy value : " << m_data << " at address " << this << std::endl;
    }
};

class LinkedList
{
    public:
        LinkedList();
        LinkedList(int cols);
        ~LinkedList();

        void printRow();
        void printRowNonZero();
        void setValue(int data, int col);
        int getValue(int col);
        void add(LinkedList& other);

    protected:

    private:
        ColumnNode* head {};
        ColumnNode* tail {};
        int length = 0;
        // total number of columns
        int m_cols{};

        void link(ColumnNode* first, ColumnNode* second){
            if(first)
                first->next = second;

            if(second)
                second->prev = first;
        }

        ColumnNode* embedAfter(ColumnNode* nodeBefore, int data, int col){
            ColumnNode* middle = new ColumnNode(data, col);
            ++length;

            ColumnNode* nodeAfter = nodeBefore->next;
            link(nodeBefore, middle);

            if(!nodeAfter)
                tail = middle;
            else
                link(middle, nodeAfter);

            return middle;
        }

        //return the node of this column
        ColumnNode* getCol(int col, bool isCreateIfMissing){
            ColumnNode* prevCol = head;
            //find the node with col-1
            while(prevCol->next && prevCol->next->m_column == col){
                prevCol = prevCol->next;
            }

            bool found = prevCol->next && prevCol->next->m_column == col;

            if(found)
                return prevCol->next;

            if(!isCreateIfMissing)
                return nullptr;

            return embedAfter(prevCol, 0, col);
        }
};

struct RowNode {
    int m_row{};
    LinkedList colList;

    RowNode* next {};
    RowNode* prev {};

    RowNode(int row, int cols) : m_row(row), colList(cols){}

    ~RowNode() {
        std::cout << "Destroy value : " << " at address " << this << std::endl;
    }
};

#endif // LINKEDLIST_H
