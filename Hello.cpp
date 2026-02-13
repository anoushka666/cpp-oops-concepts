/*private = Student ID, study hours, + operator to add, - operator to deduct,
 student 1 = +10, student 2 = -5, friend func to compare and access*/

#include<iostream>
using namespace std;
class Student{
    private:
    int ID;
    int hours;

    public:
    //initialize the values
    Student(int a, int b): ID(a), hours(b){}

    Student operator+ (int time){
        return Student(ID, hours+time);

    }
    Student operator- (int time){
        return Student(ID, hours-time);

    }
    friend void compare(const Student &s1, const Student &s2);

    void display(){
        cout<<"Student ID: "<<ID<<endl<<"Student hours: "<<hours<<endl;
    }

};
 
void compare(const Student &s1, const Student &s2){
    cout<<"Study hours of student "<<s1.ID<<" = "<<s1.hours<<endl;
    cout<<"Study hours of student "<<s2.ID<<" = "<<s2.hours<<endl;

    if (s1.hours==s2.hours){
        cout<<"Both students have same study time";
    }
    else if (s1.hours>s2.hours){
        cout<<"Student 1 has more study hours";
    }
    else{
        cout<<"Student 2 has more study hours";
    }
}
int main(){
    Student s1(101, 100);
    Student s2(102, 55);
    Student s3 = s1+10;
    Student s4 = s2-5;

    s3.display();
    s4.display();
    compare(s1,s2);
}
