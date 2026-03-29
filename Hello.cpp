#include<iostream>
#include<cstring>
using namespace std;
class Student{
    protected:
string name;
int roll;
    public:
Student(string n, int r){
    name = n;
    roll = r;
}
};
class Researcher: virtual public Student{
    protected:
int published;
int citations;
    public:
Researcher(string n, int r, int p, int c): Student (n,r){
        published = p;
        citations = c;
    }
};
class Debater: virtual public Student{
    protected:
int won;
int award;
    public:
Debater(string n, int r, int w, int a): Student (n,r){
        won = w;
        award = a;
    }
};
class TopScholar: public Researcher, public Debater{
public:
float scholarshipIndex;
TopScholar(string n, int r, int p,  int c, int w, int a):Student(n,r), Researcher(n, r, p, c), Debater(n, r, w, a){;

scholarshipIndex = (float)(published-5)/published + (float)(won-3)/won;
if (scholarshipIndex>0){
    cout<<"Student is a Top Scholar! "<<endl;
    cout<<"Student name: "<<name<<endl;
    cout<<"Student roll number: "<<roll<<endl;
    
}
else{
    cout<<"Student is not a Top Scholar!"<<endl;
}
}
};
int main(){
    TopScholar t1("Anoushka", 239, 10, 200, 5, 3);
    TopScholar t2("Aana", 232, 4, 150, 2, 5);

}
