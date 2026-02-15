#include<iostream>
using namespace std;
class Vehicle{
    public:
    virtual void display(){
        cout<<"This is a vehicle"<<endl;
    }
    virtual ~Vehicle() {}  //virtaul destructor
};
class Car: public Vehicle{
    public:
    void display() override{   //override
        cout<<"This is a car"<<endl;
    }};
class Bike: public Vehicle{
    public:
    void display() override{
        cout<<"This is a bike"<<endl;
    }};
int main(){
    Vehicle *vehicle[2];
    vehicle[0] = new Car();
    vehicle[1] = new Bike();
    for (int i=0; i<2; i++){
        vehicle[i]->display();
    }
    for (int i=0; i<2; i++){
        delete vehicle[i];
    }
}
