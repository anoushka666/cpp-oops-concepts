
#include <iostream>
using namespace std;

/* =====================================
   (a) Class Point – Constructor Overloading
   ===================================== */
class Point {
    int x, y;

public:
    // i. Default constructor (origin)
    Point() {
        x = 0;
        y = 0;
    }

    // ii. Parameterized constructor
    Point(int a, int b) {
        x = a;
        y = b;
    }

    // iii. Copy constructor
    Point(Point &p) {
        x = p.x;
        y = p.y;
    }

    void display() {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

/* =====================================
   (b) Class Distance – Friend Function
   ===================================== */
class Distance {
    int feet;
    int inches;

public:
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    friend void compareDistance(Distance, Distance);
};

void compareDistance(Distance d1, Distance d2) {
    int total1 = d1.feet * 12 + d1.inches;
    int total2 = d2.feet * 12 + d2.inches;

    if (total1 > total2)
        cout << "First distance is larger" << endl;
    else
        cout << "Second distance is larger" << endl;
}

/* =====================================
   (c) Class Account – Fund Transfer
   ===================================== */
class Account {
    int accountNumber;
    float balance;

public:
    Account(int acc, float bal) {
        accountNumber = acc;
        balance = bal;
    }

    friend void transferFunds(Account &, Account &, float);

    void display() {
        cout << "Account " << accountNumber
             << " Balance: " << balance << endl;
    }
};

void transferFunds(Account &from, Account &to, float amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

/* =====================================
   (d) Class Time – Add Two Times
   ===================================== */
class Time {
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    friend Time addTime(Time, Time);

    void display() {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

Time addTime(Time t1, Time t2) {
    Time result;

    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + (result.seconds / 60);
    result.seconds %= 60;
    result.hours = t1.hours + t2.hours + (result.minutes / 60);
    result.minutes %= 60;

    return result;
}

/* =====================================
   Main Function
   ===================================== */
int main() {

    // (a) Point
    Point p1;
    Point p2(4, 5);
    Point p3(p2);

    p1.display();
    p2.display();
    p3.display();

    // (b) Distance
    Distance d1(5, 6);
    Distance d2(6, 2);
    compareDistance(d1, d2);

    // (c) Account
    Account a1(101, 5000);
    Account a2(102, 3000);

    transferFunds(a1, a2, 1000);
    a1.display();
    a2.display();

    // (d) Time
    Time t1(2, 45, 50);
    Time t2(1, 20, 30);

    Time t3 = addTime(t1, t2);
    t3.display();

    return 0;
}
