
#include<iostream>
using namespace std;

class Person{
public:
    string name;
    int age;
    virtual void getdata()=0;
    virtual void putdata()=0;
};

class Professor: public Person{
    int publications;
    int cur_id;
    static int id;
public:
    Professor(){ cur_id=++id; }

    void getdata(){
        cin>>name>>age>>publications;
    }

    void putdata(){
        cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
    }
};

int Professor::id=0;

class Student: public Person{
    int marks[6];
    int cur_id;
    static int id;
public:
    Student(){ cur_id=++id; }

    void getdata(){
        cin>>name>>age;
        for(int i=0;i<6;i++) cin>>marks[i];
    }

    void putdata(){
        int sum=0;
        for(int i=0;i<6;i++) sum+=marks[i];
        cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
    }
};

int Student::id=0;

int main(){
    Person *per[2];

    Professor p;
    Student s;

    per[0]=&p;
    per[1]=&s;

    per[0]->getdata();
    per[1]->getdata();

    per[0]->putdata();
    per[1]->putdata();

    return 0;
}

