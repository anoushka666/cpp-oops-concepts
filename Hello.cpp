#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check balanced brackets
bool isBalanced(string expr) {
    stack<char> s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {

            // If stack is empty
            if (s.empty()) {
                return false;
            }

            char top = s.top();
            s.pop();

            // Matching conditions
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack becomes empty → balanced
    return s.empty();
}

int main() {
    string expr;

    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "Balanced Expression" << endl;
    } else {
        cout << "Not Balanced Expression" << endl;
    }

    return 0;
}
