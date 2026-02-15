#include <iostream>
#include <string>
using namespace std;
class Gift {
protected:
    string senderName;
    string recipientName;
    double price;

public:
    Gift(string s="", string r="", double p=0.0)
        : senderName(s), recipientName(r), price(p) {}

    virtual void displayDetails(){
        cout << "Sender: " << senderName << endl;
        cout << "Recipient: " << recipientName << endl;
        cout << "Price: Rs" << price << endl;
    }

    friend void printGiftDetails(Gift );
};

class Flower : public Gift {
private:
    string flowerType;
    string color;
    string arrangementStyle;

public:
    Flower(string s, string r, double p,
           string type, string c, string style)
        : Gift(s, r, p),
          flowerType(type), color(c), arrangementStyle(style) {}

    void displayDetails(){
        Gift::displayDetails();
        cout << "Flower Type: " << flowerType << endl;
        cout << "Color: " << color << endl;
        cout << "Arrangement Style: " << arrangementStyle << endl;
    }

    friend void printGiftDetails(Gift );
};
class ChocolateBox : public Gift {
private:
    string chocolateType;
    string flavor;
    int quantity;

public:
    ChocolateBox(string s, string r, double p,
                 string type, string f, int q)
        : Gift(s, r, p),
          chocolateType(type), flavor(f), quantity(q) {}

    void displayDetails(){
        Gift::displayDetails();
        cout << "Chocolate Type: " << chocolateType << endl;
        cout << "Flavor: " << flavor << endl;
        cout << "Quantity: " << quantity << endl;
    }

    friend void printGiftDetails(Gift);
};

class Card : public Gift {
private:
    string messageContent;
    string style;

public:
    Card(string s, string r, double p,
         string msg, string st)
        : Gift(s, r, p),
          messageContent(msg), style(st) {}

    void displayDetails(){
        Gift::displayDetails();
        cout << "Message: " << messageContent << endl;
        cout << "Style: " << style << endl;
    }

    friend void printGiftDetails(Gift);
};

void printGiftDetails(Gift g) {
    cout << "\nGift Details\n";
    g.displayDetails();  
}
int main() {

    Flower f("Alice", "Bob", 50.0,
             "Rose", "Red", "Bouquet");

    ChocolateBox cb("John", "Emma", 30.0,
                    "Dark Chocolate", "Hazelnut", 12);

    Card c("Sophia", "Liam", 10.0,
           "Happy Birthday!", "Elegant");

    cout << "\nFlower Gift:\n";
    f.displayDetails();

    cout << "\nChocolate Box Gift:\n";
    cb.displayDetails();

    cout << "\nCard Gift:\n";
    c.displayDetails();

    printGiftDetails(f);
    printGiftDetails(cb);
    printGiftDetails(c);

    return 0;
}
