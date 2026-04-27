#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int Q;
        cin >> Q;

        vector<int> A;

        while (Q--) {
            char ch;
            cin >> ch;

            if (ch == 'a') {
                int x;
                cin >> x;
                A.push_back(x);
            }
            else if (ch == 'b') {
                sort(A.begin(), A.end()); 
            }
            else if (ch == 'c') {
                reverse(A.begin(), A.end());
            }
            else if (ch == 'd') {
                cout << A.size() << endl;
            }
            else if (ch == 'e') {
                for (int x : A) cout << x << " ";
                cout << endl;
            }
            else if (ch == 'f') {
                sort(A.begin(), A.end(), greater<int>());
            }
        }
    }

    return 0;
}
