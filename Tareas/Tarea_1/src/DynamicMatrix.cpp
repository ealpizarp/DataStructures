#include "DynamicMatrix.h"


    DynamicMatrix::DynamicMatrix(int rows, int cols)
        {

        if (rows <= 0 || cols <= 0) {
            throw runtime_error("Invalid number of rows or columns.");
        }
        this->rows = rows;
        this->cols = cols;
        matrix = new E*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new E[cols];
        }

        }

        T DynamicMatrix::getValue(int r, int c)
        {
          checkIndexes(r,c);
          return Matrix[r][c];

        }

        void DynamicMatrix::setValue(int r, int c, T element)
        {
           checkIndexes(r,c);
           matrix[r][c] = element;

        }

        int DynamicMatrix::getRows()
        {
            return rows;
        }

        int DynamicMatrix::getColumns()
        {
            return cols;
        }

        void DynamicMatrix::checkIndexes(int r, int c){
        if (r < 0 || r >= rows) {
            throw runtime_error("Invalid row.");
        }
        if (c < 0 || c >= cols) {
            throw runtime_error("Invalid column.");
        }
        }

    DynamicMatrix::~DynamicMatrix()
        {
        for (int i = 0; i < rows; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
        }

