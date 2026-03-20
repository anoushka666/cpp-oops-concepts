#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char str[100];

public:
    MyString() {
        strcpy(str, "");
    }

    MyString(const char s[]) {
        strcpy(str, s);
    }

    MyString operator+(MyString s) {
        MyString temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    MyString s1("Hello ");
    MyString s2("World");
    MyString s3;

    s3 = s1 + s2;   // operator overloading
    s3.display();

    return 0;
}
