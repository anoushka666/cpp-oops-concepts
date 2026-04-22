#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    Person(string n){
        name = n;
        cout<<"I am a person"<<endl;
        }
    virtual void display(){
        cout<<"Name: "<<name<<endl;
    }
};
class Employee: public Person{
    public:
    double salary;
    Employee(string n, double s): Person(n){
        salary = s;
        cout<<"I am employee"<<endl;
    }
    void display() override {
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;

    }
};
class Manager: public Employee{
    public:
    int teamsize;
    Manager(string n, int s, int t): Employee(n, s){
        teamsize = t;
        cout<<"I am manager"<<endl;
    }
     void display() override{
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Team size: "<<teamsize<<endl;
    }
};
int main(){
Person *p1 = new Person("Anoushka");
p1->display();
Person *p2 = new Employee("Abhay", 10000);
p2->display();
Person *p3 = new Manager("Vertika", 50000, 3);
p3->display();
delete p1;
delete p2;
delete p3;
}
