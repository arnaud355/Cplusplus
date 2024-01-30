#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H


class SparseMatrix
{
    public:
        SparseMatrix();
        SparseMatrix(int lengthX, int lengthY);
        ~SparseMatrix();

    protected:

    private:
        Node* head {};
        Node* tail {};
        int m_lengthX = 0;
        int m_lengthY = 0;
};

#endif // SPARSEMATRIX_H
