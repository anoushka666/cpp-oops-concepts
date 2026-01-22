#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
    int enroll_no;
    string name;
    string branch;
    float cgpa;

    public:
    Student(int en, string n, string b, float c){
        enroll_no = en;
        name = n;
        branch = b;
        cgpa = c;
    }

    Student(int en, string n, float c){
        enroll_no = en;
        name = n;
        branch = "CSE";
        cgpa = c;
    }

    Student(){
        enroll_no = 1;
        name = "Unknown";
        branch = "CSE";
        cgpa = 6;
    }

    void setcgpa(float a){
        cgpa = a;
    }

    float getcgpa(){
        return cgpa;
    }

    void print(){
        cout<<endl<<"Name: "<<name<<endl;
        cout<<"Enrollment number: "<<enroll_no<<endl;
        cout<<"Branch: "<<branch<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
    }
};
int main(){
    Student s1 (123, "Anoushka", "CSE", 9.8);
    Student s2 (124, "Mark", 8.7);
    Student s3;

    s2.setcgpa(9);
    s2.getcgpa();
    s1.print();
    s2.print();
    s3.print();
}
