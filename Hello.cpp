#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int maxSocksOnTable(vector<int>& arr) {
    unordered_set<int> seen;
    int current = 0, maxi = 0;

    for (int x : arr) {
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            current++;
        } else {
            
            current--;
        }
        maxi = max(maxi, current);
    }

    return maxi;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 2, 3}; 
    cout << maxSocksOnTable(arr);
    return 0;
}
