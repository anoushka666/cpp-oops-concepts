#include<iostream>
using namespace std;
template <class T>
class Calculator{
    public:
    T a;
    T b;
    Calculator(){
        cout<<"Enter two numbers: ";
        cin>>a>>b;

        cout<<"Addition: "<<a+b<<endl;
        cout<<"Subtraction: "<<a-b<<endl;
        cout<<"Multiplication: "<<a*b<<endl;
        if (b==0){
            cout<<"Division by 0 not possible";
        }
        else {
            cout<<"Division: "<<a/b<<endl;
        }

    }
};
int main(){
    Calculator <int>c1;
    Calculator <float>c2;
}
