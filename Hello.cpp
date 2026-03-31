#include<iostream>
using namespace std;
class Person{
    public:
    Person(int x){
        cout << "Person::Person(x) called!" << endl;
    }
};
class Faculty : virtual public Person{
    public:
    Faculty(int x) : Person(x){
        cout << "Faculty::Faculty(x) called!" << endl;
    }
};
class Student : virtual public Person{
    public:
    Student(int x) : Person(x){
        cout << "Student::Student(x) called!" << endl;
    }
};

class TA : public Faculty, public Student{
    public:
    TA(int x) : Person(x), Faculty(x), Student(x){
        cout << "TA::TA called!" << endl;
    }
};

int main(){
    TA t1(30);
}
