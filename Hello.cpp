#include<iostream>
using namespace std;
class Time{
    private:
    int hours;
    int mins;

    public:
    void getTime(){
        cout<<"Enter time in hours: ";
        cin>>hours;
        cout<<"Enter time in mins: ";
        cin>>mins; 
    }

    Time operator + (Time t){
        Time temp;
        temp.hours = hours + t.hours;
        temp.mins = mins + t.mins;
        
        temp.hours = temp.hours + temp.mins/60;
        temp.mins = temp.mins % 60;
        return temp;
    }

    void display(){
        cout<<"Total time: "<<hours<<" hours and "<<mins<<" mins"<<endl;
    }
};
int main(){
    Time t1;
    t1.getTime();
    Time t2;
    t2.getTime();
    Time t3 = t1+t2;
    t3.display();

}
