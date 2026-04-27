#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void replaceWithRank(vector<int>& arr) {
    int n = arr.size();

   
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == temp[j]) {
                arr[i] = j + 1; 
                break;
            }
        }
    }
}

int main() {
    vector<int> arr = {40, 10, 20, 30};

    replaceWithRank(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
