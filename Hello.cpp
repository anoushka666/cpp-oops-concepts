#include<iostream>
using namespace std;
class Rectangle{
    private:
    float length;
    float breadth;

    public:
    Rectangle(){
        length = 0;
        breadth = 0;
    }
    Rectangle(float l, float b){
        length = l;
        breadth = b;
    }
    
    void setter(){
        cout<<"Enter values: ";
        cin>>length>>breadth;
    }
    void getter(){
        cout<<"Length: "<<length<<endl;
        cout<<"Breadth: "<<breadth<<endl;
    }
    void calculateArea(){
        cout<<"Area of rectangle: "<<length*breadth<<endl;
    }
    ~Rectangle(){
        cout<<"Object destroyed!"<<endl;
    }
};
int main(){
    Rectangle r1(10,5);
    r1.getter();
    r1.calculateArea();

    Rectangle r2;
    r2.setter();
    r2.getter();
    r2.calculateArea();
}
