#ifndef DYNAMICMATRIX_H
#define DYNAMICMATRIX_H
#include<stdexcept>

using std::runtime_error;

template <typename T>

class DynamicMatrix
{
    public:

        DynamicMatrix(int rows, int cols)
        {

        if (rows <= 0 || cols <= 0) {
            throw runtime_error("Invalid number of rows or columns.");
        }
        this->rows = rows;
        this->cols = cols;
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }

        }

        T getValue(int r, int c)
        {
          checkIndexes(r,c);
          return matrix[r][c];

        }

        void setValue(int r, int c, T element)
        {
           checkIndexes(r,c);
           matrix[r][c] = element;

        }

        void setAll(T value){

        for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            setValue(r, c, value);
        }
        }
        }

        int getRows()
        {
            return rows;
        }

        int getColumns()
        {
            return cols;
        }

        void traspose(){

        int ro = 0;
        int co = 0;

        if (rows <= 0 || cols <= 0) {
            throw runtime_error("Invalid number of rows or columns.");
        }

        T traspose[cols][rows];

           for (int r = 0; r < cols; r++) {
        for (int c = 0; c < rows; c++) {
           traspose[r][c]=matrix[c][r];
        }
        }

        for (int i = 0; i < rows; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;


        ro=rows;
        co= cols;

        this->rows=co;
        this->cols=ro;

        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }

        for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
           matrix[r][c]=traspose[r][c];
        }
        }

        }







    void addRow(T value){

		int aux;
		aux = rows;
		aux++;

		T** newMatrix = new T*[aux];
        newMatrix[rows]=new T[cols];
        	for (int i = 0; i < rows; i++) {
			newMatrix[i] = matrix[i];
			}
           for (int i = 0; i < cols; i++) {
            newMatrix[rows][i]=value;
                 }
        delete [] matrix;
        this->rows=aux;
        matrix = new T*[rows];


	for (int i = 0; i < rows; i++) {

			matrix[i] = newMatrix[i];
			}

        delete[] newMatrix;
    }





    void addColumn(T value) {

traspose();
addRow(value);
traspose();
    }

void removeRow(int value){

  if (value < 0 || value >= rows) {
            throw runtime_error("Invalid row.");
        }
    delete [] matrix[value];
    T **tmp = new T*[rows - 1];
    int tmpI = 0;
    for(int i = 0; i < rows; i++)
        if(i != value)
            tmp[tmpI++] = matrix[i];
    delete [] matrix;
    matrix = tmp;
    rows = rows - 1;

}

void removeCol(int value){
  if (value < 0 || value >= cols) {
            throw runtime_error("Invalid row.");
        }

traspose();
removeRow(value);
traspose();

}






	void print() {

		for (int r = 0; r < getRows(); r++) {
			for (int c = 0; c < getColumns(); c++) {
				std::cout << "[" << getValue(r, c) << "]" << "\t";
			}
			std::cout<<"        pos:"<<r<<std::endl;
		}
	}


        ~DynamicMatrix()
        {
        for (int i = 0; i < rows; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
        }

    private:

        int cols;
        int rows;
        T** matrix;

        void checkIndexes(int r, int c){
        if (r < 0 || r >= rows) {
            throw runtime_error("Invalid row.");
        }
        if (c < 0 || c >= cols) {
            throw runtime_error("Invalid column.");
        }
        }





};

#endif // DYNAMICMATRIX_H
