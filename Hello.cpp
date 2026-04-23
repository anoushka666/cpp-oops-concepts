#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void generateSubsets(const vector<int>& arr, vector<int>& current, int index) {

    if (index == arr.size()) {
        cout << "{ ";
        for (size_t i = 0; i < current.size(); ++i) {
            cout << current[i];
            if (i < current.size() - 1) cout << ", ";
        }
        cout << " }" << endl;
        return;
    }


    current.push_back(arr[index]);
    generateSubsets(arr, current, index + 1);


    current.pop_back();
    generateSubsets(arr, current, index + 1);
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";

    #include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Recursive function to generate all subsets
void generateSubsets(const vector<int>& arr, vector<int>& current, int index) {
    // Base case: if index reaches the end, print the current subset
    if (index == arr.size()) {
        cout << "{ ";
        for (size_t i = 0; i < current.size(); ++i) {
            cout << current[i];
            if (i < current.size() - 1) cout << ", ";
        }
        cout << " }" << endl;
        return;
    }

    // Include the current element
    current.push_back(arr[index]);
    generateSubsets(arr, current, index + 1);

    // Exclude the current element (backtrack)
    current.pop_back();
    generateSubsets(arr, current, index + 1);
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    
    // Validate input for size
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        while (!(cin >> arr[i])) {
            cerr << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "\nAll subsets:\n";
    vector<int> current;
    generateSubsets(arr, current, 0);

    return 0;
}

    if (!(cin >> n) || n < 0) {
        cerr << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        while (!(cin >> arr[i])) {
            cerr << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "\nAll subsets:\n";
    vector<int> current;
    generateSubsets(arr, current, 0);

    return 0;
}
