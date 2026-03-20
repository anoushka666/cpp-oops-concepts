#include <iostream>
using namespace std;

int main() {
    int d, r, c;
    cin >> d >> r >> c;

    // Step 1: allocate depth
    int ***arr = new int**[d];

    // Step 2: allocate rows
    for (int i = 0; i < d; i++) {
        arr[i] = new int*[r];
        for (int j = 0; j < r; j++) {
            // Step 3: allocate columns
            arr[i][j] = new int[c];
        }
    }

    // Input
    for (int i = 0; i < d; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                cin >> arr[i][j][k];

    // Output
    for (int i = 0; i < d; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++)
                cout << arr[i][j][k] << " ";
            cout << endl;
        }
    }

    // Free memory
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < r; j++)
            delete[] arr[i][j];
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
