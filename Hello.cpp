#include<iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Rectangle : public Shape {
    float l, b;
public:
    Rectangle(float l, float b) { this->l=l; this->b=b; }
    float area() { return l*b; }
    float perimeter() { return 2*(l+b); }
};

class Square : public Shape {
    float s;
public:
    Square(float s){ this->s=s; }
    float area(){ return s*s; }
    float perimeter(){ return 4*s; }
};

class Circle : public Shape {
    float r;
public:
    Circle(float r){ this->r=r; }
    float area(){ return 3.14*r*r; }
    float perimeter(){ return 2*3.14*r; }
};

int main(){
    Shape *s;

    Rectangle r(4,5);
    s=&r;
    cout<<"Rectangle Area: "<<s->area()<<endl;
    cout<<"Rectangle Perimeter: "<<s->perimeter()<<endl;

    Square sq(4);
    s=&sq;
    cout<<"Square Area: "<<s->area()<<endl;
    cout<<"Square Perimeter: "<<s->perimeter()<<endl;

    Circle c(3);
    s=&c;
    cout<<"Circle Area: "<<s->area()<<endl;
    cout<<"Circle Perimeter: "<<s->perimeter()<<endl;

    return 0;
}
