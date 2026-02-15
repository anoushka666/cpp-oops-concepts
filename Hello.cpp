#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        publicationYear = y;
    }
    friend ostream& operator<<(ostream& out, const Book& b);
};

ostream& operator<<(ostream& out, const Book& b) {
    out << "Title: " << b.title << endl;
    out << "Author: " << b.author << endl;
    out << "Publication Year: " << b.publicationYear << endl;
    return out;
}

int main() {
    Book b1("The Alchemist", "Paulo Coelho", 1988);
    Book b2("Atomic Habits", "James Clear", 2018);

    cout << "Book 1 Details:\n";
    cout << b1 << endl;

    cout << "Book 2 Details:\n";
    cout << b2 << endl;

    return 0;
}
