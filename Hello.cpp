#include <iostream>
#include <limits>
using namespace std;

bool isSortedDescending(const int arr[], int n) {

    if (n <= 1) {
        return true;
    }

    if (arr[n - 2] < arr[n - 1]) {
        return false;
    }

    return isSortedDescending(arr, n - 1);
}

int main() {
    int n;

    cout << "Enter number of elements in the array: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative integer.\n";
        return 1;
    }

    if (n == 0) {
        cout << "Empty array is considered sorted.\n";
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        while (!(cin >> arr[i])) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (isSortedDescending(arr, n)) {
        cout << "The array is sorted in descending order.\n";
    } else {
        cout << "The array is NOT sorted in descending order.\n";
    }

    delete[] arr;
    return 0;
}
