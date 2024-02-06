#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "DoubleLinkedList.h"
#include "ArrayLinkedList.h"
#include "LinkedList.h"
#include <vector>

class SparseMatrix
{
    public:
        SparseMatrix();
        SparseMatrix(int rows, int cols);
        ~SparseMatrix();
        void setValue(int data, int row, int col);
        int getValue(int row, int col);
        void printMatrix();
        void printMatrixNonZero();
        void add(SparseMatrix& other);
        void testCol();
        int getRows();
        int getCols();
        void testSparse();

    protected:

    private:
        RowNode* head {};
        RowNode* tail {};
        int length = 0;
        int m_rows{};
        int m_cols{};

        void link(RowNode* first, RowNode* second){
            if(first)
                first->next = second;

            if(second)
                second->prev = first;
        }

        RowNode* embedAfter(RowNode* nodeBefore, int row){
            RowNode* middle = new RowNode(row, m_cols);
            ++length;

            RowNode* nodeAfter = nodeBefore->next;
            link(nodeBefore, middle);

            if(!nodeAfter)
                tail = middle;
            else
                link(middle, nodeAfter);

            return middle;
        }

         RowNode* getRow(int row, bool isCreateIfMissing){
            RowNode* prevRow = head;
            //find the node with col-1
            while(prevRow->next && prevRow->next->m_row < row){
                prevRow = prevRow->next;
            }

            bool found = prevRow->next && prevRow->next->m_row == row;

            if(found)
                return prevRow->next;

            if(!isCreateIfMissing)
                return nullptr;

            return embedAfter(prevRow, row);
        }

};

#endif // SPARSEMATRIX_H
