#include<iostream>
using namespace std;

class Person{
protected:
    int id;
    string name;

public:
    Person(int a, string n){
        id = a;
        name = n;
        cout << "Person constructor!" << endl;
    }

    virtual void displayRole(){
        cout << "This is a person" << endl;
    }
};

class Teacher : virtual public Person{
protected:
    string subject;

public:
    Teacher(int a, string n, string s) : Person(a, n){
        subject = s;
        cout << "Teacher constructor!" << endl;
    }

    void displayRole(){
        cout << "This is a teacher" << endl;
    }
};

class Researcher : virtual public Person{
protected:
    string field;

public:
    Researcher(int a, string n, string f) : Person(a, n){
        field = f;
        cout << "Researcher constructor!" << endl;
    }

    void displayRole(){
        cout << "This is a researcher" << endl;
    }
};

class Professor : public Teacher, public Researcher{
protected:
    string publications;

public:
    Professor(int a, string n, string s, string f, string p)
        : Person(a, n), Teacher(a, n, s), Researcher(a, n, f){
        publications = p;
        cout << "Professor constructor!" << endl;
    }

    void displayRole(){
        cout << "This is a professor" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Subject: " << subject << endl;
        cout << "Field: " << field << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main(){
    Professor p1(239, "Anoushka", "Maths", "Algebra", "JIIT");
    p1.displayRole();
}
