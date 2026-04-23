#include <iostream>
#include <iomanip>
using namespace std;


struct Node {
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};


class Polynomial {
private:
    Node* head;

    void insertTerm(int coeff, int exp) {
        if (coeff == 0) return;

        Node* newNode = new Node(coeff, exp);

        if (!head || exp > head->exp) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;


        while (curr && curr->exp > exp) {
            prev = curr;
            curr = curr->next;
        }


        if (curr && curr->exp == exp) {
            curr->coeff += coeff;
            delete newNode;
            if (curr->coeff == 0) {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                delete curr;
            }
        } else {

            newNode->next = curr;
            if (prev) prev->next = newNode;
            else head = newNode;
        }
    }

public:
    Polynomial() : head(nullptr) {}

    void addTerm(int coeff, int exp) {
        insertTerm(coeff, exp);
    }


    void display() const {
        if (!head) {
            cout << "0";
            return;
        }
        Node* curr = head;
        bool firstTerm = true;
        while (curr) {
            if (!firstTerm && curr->coeff > 0) cout << " + ";
            if (curr->coeff < 0) cout << " - ";

            int absCoeff = abs(curr->coeff);
            if (absCoeff != 1 || curr->exp == 0) cout << absCoeff;
            if (curr->exp > 0) {
                cout << "x";
                if (curr->exp > 1) cout << "^" << curr->exp;
            }
            firstTerm = false;
            curr = curr->next;
        }
    }


    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1) {
            result.insertTerm(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        while (p2) {
            result.insertTerm(p2->coeff, p2->exp);
            p2 = p2->next;
        }
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        Polynomial result;
        for (Node* p1 = head; p1 != nullptr; p1 = p1->next) {
            for (Node* p2 = other.head; p2 != nullptr; p2 = p2->next) {
                result.insertTerm(p1->coeff * p2->coeff, p1->exp + p2->exp);
            }
        }
        return result;
    }


    ~Polynomial() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    Polynomial poly1, poly2;


    cout << "Enter first polynomial terms (coeff exp), end with 0 0:\n";
    while (true) {
        int c, e;
        cin >> c >> e;
        if (c == 0 && e == 0) break;
        poly1.addTerm(c, e);
    }

    cout << "Enter second polynomial terms (coeff exp), end with 0 0:\n";
    while (true) {
        int c, e;
        cin >> c >> e;
        if (c == 0 && e == 0) break;
        poly2.addTerm(c, e);
    }

    cout << "\nFirst Polynomial: ";
    poly1.display();
    cout << "\nSecond Polynomial: ";
    poly2.display();

    Polynomial sum = poly1.add(poly2);
    Polynomial product = poly1.multiply(poly2);

    cout << "\n\nSum: ";
    sum.display();
    cout << "\nProduct: ";
    product.display();
    cout << endl;

    return 0;
}
