#ifndef DYNAMICMATRIX_H
#define DYNAMICMATRIX_H
#include<iostream>
#include<stdexcept>

using namespace std;

template <typename E>

class DynamicMatrix
{
private:
	int rows;
	int cols;
	E** matrix;

public:
	DynamicMatrix(int rows, int cols) {
		if (rows <= 0 || cols <= 0) {
			cout << "invalid name" << endl;
		}
		this->rows = rows;
		this->cols = cols;
		matrix = new E * [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new E[cols];
		}
	}
	~DynamicMatrix() {
		for (int i = 0; i < rows; i++) {
			delete[]matrix[i];
		}
		delete[] matrix;
	}

	E getValue(int rows, int cols) {

		if (r < 0 || r >= rows) {
			cout << "Invalid row" << endl;
		}

		if (this->cols<0 || this->cols > cols) {
			cout << "Invalid col" << endl;
		}

		return matric[r][c];
	}

	void setValue(int rows, int cols, E element) {

	}

};



#endif // !DynamicMatrix

