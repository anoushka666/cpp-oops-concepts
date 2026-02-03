#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **elements;

public:
    // Constructor
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        elements = new int*[rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                elements[i][j] = 0;
            }
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] elements[i];
        }
        delete[] elements;
    }

    // Get number of rows
    int getRows() {
        return rows;
    }

    // Get number of columns
    int getCols() {
        return cols;
    }

    // Set element at position (i, j)
    void setElement(int i, int j, int value) {
        elements[i][j] = value;
    }

    // Add two matrices
    Matrix add(Matrix &m) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.elements[i][j] = elements[i][j] + m.elements[i][j];
            }
        }
        return result;
    }

    // Multiply two matrices
    Matrix multiply(Matrix &m) {
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.elements[i][j] += elements[i][k] * m.elements[k][j];
                }
            }
        }
        return result;
    }

    // Display matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << " ";
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

    cout << "Addition Result:\n";
    C.display();

    cout << "\nMultiplication Result:\n";
    D.display();

    return 0;
}
