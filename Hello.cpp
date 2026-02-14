#include<iostream>
#include<string>
using namespace std;
class Student{
    protected:
    int roll;
    string name;

    public:
    void setStudent(){
        cout<<"Enter roll and name: ";
        cin>>roll>>name;
    }
    void displayStudent(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll: "<<roll<<endl;
    }
};

class Cricketer: virtual public Student{
    protected:
    int runs;
    int wickets;
    public:
    void setCricketer(){
        cout<<"Enter runs and wickets: ";
        cin>>runs>>wickets;
    }
    void displayCricketer(){
        cout<<"Runs: "<<runs<<endl;
        cout<<"Wickets: "<<wickets<<endl;
    }

};
class Footballer: virtual public Student{
    protected:
    int goals;
    int assists;
    public:
    void setFootballer(){
        cout<<"Enter goals and assists: ";
        cin>>goals>>assists;
    }
    void displayFootballer(){
        cout<<"Goals: "<<goals<<endl;
        cout<<"Assists: "<<assists<<endl;
    }
};
class Star: public Cricketer, public Footballer{
    public:
    float index;
    void calculateIndex(){
        index = (float)(runs-1000)/runs + (goals-10)/goals;
    }
    void displayStar(){
        if(index>0){
            cout<<"Star performer details: "<<endl;
            displayStudent();
            displayCricketer();
            displayFootballer();
        }
        else{
            cout<<"Student is not star performer"<<endl;
        }
    }
    void setAll(){
        setStudent();
        setFootballer();
        setCricketer();   
    }
};
int main(){
    Star s1;
    s1.setAll();
    s1.calculateIndex();
    s1.displayStar();
}
