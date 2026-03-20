#include <iostream>
using namespace std;

class Container {
private:
    int length, width, height;

public:
    Container(int l = 0, int w = 0, int h = 0) {
        length = l;
        width = w;
        height = h;
    }

    int getLength() const { return length; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    int volume() const {
        return length * width * height;
    }

    // Declare non-member functions as friends
    friend Container operator*(const Container&, int);
    friend ostream& operator<<(ostream&, const Container&);
};

// Non-member operator * (scaling)
Container operator*(const Container& c, int k) {
    int l = c.length * k;
    int w = c.width * k;
    int h = c.height * k;

    if (l > 1000) l = 1000;
    if (w > 1000) w = 1000;
    if (h > 1000) h = 1000;

    return Container(l, w, h);
}

// Non-member operator <<
ostream& operator<<(ostream& out, const Container& c) {
    out << "Length = " << c.length
        << ", Width = " << c.width
        << ", Height = " << c.height
        << ", Volume = " << c.volume();
    return out;
}

int main() {
    int l, w, h, k;

    cout << "Enter container dimensions (L W H): ";
    cin >> l >> w >> h;

    cout << "Enter scaling factor: ";
    cin >> k;

    Container c1(l, w, h);

    cout << "\nOriginal Container:\n";
    cout << c1 << endl;

    Container c2 = c1 * k;

    cout << "\nScaled Container:\n";
    cout << c2 << endl;

    return 0;
}
