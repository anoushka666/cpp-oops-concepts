#include<iostream>
using namespace std;
class Demo{
    private:
    //static data members 
    static int X;
    static int Y;

    public:
    //static member function 
    static void print(){
        cout<<"Value of X: "<<X<<endl;
        cout<<"Value of Y: "<<Y<<endl;

    }
};
//static data members initialization 
int Demo::X = 10;
int Demo::Y = 20;
int main(){
    Demo OB;
    cout<<"Printing through object name"<<endl;
    OB.print();

    cout<<"Accessing class with class name"<<endl;
    Demo::print(); //preferred and correct way 
}
