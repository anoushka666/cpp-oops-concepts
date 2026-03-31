#include<iostream>
using namespace std;
class A{
    public:
    A(){
        cout<<"1"<<endl;
    }
    A(int x){
        cout<<"2"<<endl;
    }
    virtual void T2(){
        cout<<" A T2()"<<endl;
    }
    ~A(){
        cout<<"A dead"<<endl;
    }
};
class E{
    public:
    E(){
        cout<<"3"<<endl;
    }
    E(int x){
        cout<<"4"<<endl;
    }
};
class B: virtual public A{
    public:
    B(){
        cout<<"5"<<endl;
    }
    B(int x){
        cout<<"6"<<endl;
    }
    void T2(){
        cout<<"B T2()"<<endl;
    }
    ~B(){
        cout<<"B dead"<<endl;
    }
};
class C:virtual public E{
    public:
    C(){
        cout<<"7"<<endl;
    }
    C(int x){
        cout<<"8"<<endl;
    }
};
class D: public C, public B{
    public:
    D(): E(5), B(1){
        cout<<"9"<<endl;
    }
    D(int x): A(3), C(2){
        cout<<"10"<<endl;
    }
    void T2(){
        cout<<"D T2()"<<endl;   
    }
    ~D(){
        cout<<"D dead"<<endl;
    }
};
int main(){
    B *obj = new D(2);
    obj->T2();
    delete obj;
}
