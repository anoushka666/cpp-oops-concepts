#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void area(){}
};

class Circle: public Shape{
    public:
    int radius;
    Circle(int r){
        radius = r;
    }
    void area(){
        cout<<"Area is: "<<3.14*radius*radius<<endl;
    }
};
class Rectangle: public Shape{
    public:
    int length;
    int breadth;
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
    void area(){
        cout<<"Area is: "<<length*breadth<<endl;
    }
};
class Triangle: public Shape{
    public:
    int height;
    int base;
    Triangle(int h, int b){
        height = h;
        base = b;
    }
    void area(){
        cout<<"Area is: "<<0.5*height*base<<endl;
    }
};
int main(){
    Shape *s;
    Circle c(10);
    s = &c;
    s->area();
    Rectangle r(5,10);
    s = &r;
    s->area();
    Triangle t(6,2);
    s = &t;
    s->area();

}
