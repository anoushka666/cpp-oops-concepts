#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class Book{
    private:
    int bookID;
    char *author;
    char *title;
    double price;
    static int count;

    public:
    int size;
    Book(int a, const char *b, const char *c, double d){
        bookID = a;
    
        author = new char [strlen(b)+1];
        strcpy(author, b);

     
        title = new char[strlen(c)+1];
        strcpy(title, c);

        price = d;
        count++;

    }

     void display() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPrice: " << price << endl;
    }   

    static void getCount(){
        cout<<"There are "<<count<<" books in the library!"<<endl;
    }

    friend void calculateDiscount(Book &b);

    friend class LibraryAudit;

    ~Book(){
        delete[] author;
        delete[] title;
        count--;
    }
};
int Book:: count =0;

void calculateDiscount(Book &b){
        b.price = b.price - (0.1*b.price);
        cout<<"After discount, price: "<<b.price<<endl;
    }

class LibraryAudit{
public:
void audit(Book &b){
        cout << "\n--- Audit Details ---";
        cout << "\nBook ID: " << b.bookID;
        cout << "\nTitle: " << b.title;
        cout << "\nAuthor: " << b.author;
        cout << "\nPrice: " << b.price << endl;
}
    };
    int main() {


    Book b1(101, "C++ Programming", "Bjarne Stroustrup", 500);
    Book b2(102, "Data Structures", "Mark Allen Weiss", 600);

 
    b1.display();
    b2.display();

  
    Book::getCount();

   
    calculateDiscount(b1);

    LibraryAudit auditor;
    auditor.audit(b1);

    return 0;
}

