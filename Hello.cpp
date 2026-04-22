#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    Student(string n){
        name = n;
    }
    virtual void show(){
        cout<<"Student Name: "<<name<<endl;
    }
};
class Teacher{
    public:
    string name;
    Teacher(string n){
        name = n;
    }
    virtual void show(){
        cout<<"Teacher Name: "<<name<<endl;
    }
    
};
class TeachingAssistant: public Student, public Teacher{
    public:
    TeachingAssistant(string s, string t): Student(s), Teacher(t){}
        void show() override{
        cout<<"Student Name: "<<Student::name<<endl;
        cout<<"Teacher Name: "<<Teacher::name<<endl;
    }

};
int main(){
    TeachingAssistant t1("anoushka", "anoushka");
    t1.show();
    t1.Student::show();
    t1.Teacher::show();
    
}
