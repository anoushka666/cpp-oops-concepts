#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }


    int getRows() {
        return rows;
    }

 
    int getCols() {
        return cols;
    }

   
    void setElement(int i, int j, int value) {
        data[i][j] = value;
    }


    Matrix add(Matrix &m) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }

    
    Matrix multiply(Matrix &m) {
        Matrix result(rows, m.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

   
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);

    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);

    Matrix C = A.add(B);
    Matrix D = A.multiply(B);

    cout << "Addition:\n";
    C.display();

    cout << "Multiplication:\n";
    D.display();


}

