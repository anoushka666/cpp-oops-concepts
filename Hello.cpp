#include <iostream>
using namespace std;

template <class T>
class Circle {
    T rad;

public:
    // Constructor
    Circle(T r = 0) {
        rad = r;
    }

    Circle operator+(T x) {
        return Circle(rad + x);
    }

   
    Circle operator+(Circle c) {
        return Circle(rad + c.rad);
    }

    friend ostream& operator<<(ostream &out, const Circle<T> &c) {
        out << c.rad << " ";
        return out;
    }
};

int main() {
    Circle<int> c1(5), c2;   
    c2 = c2 + 3;             

    Circle<int> c3 = c1 + c2;  

    Circle<double> c4(1.5);
    c4 = c4 + 1.2;             

    cout << c3 << c4 << '\n';

    return 0;
}
