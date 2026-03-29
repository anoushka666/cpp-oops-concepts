#include<iostream>
#include<cstring>
using namespace std;

class Passenger{
    public:
    string name;
    int age;

    void input(){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }
};

class RailwayBooking{
    private:
    int ticketcount;
    static int availableSeats;
    Passenger p[100];

    public:
    void bookTickets(){
        try{
            cout<<"Enter number of tickets: ";
            cin>>ticketcount;

            if (ticketcount<=0){
                cout<<"Invalid ticket count! Try again";
            }
            if (ticketcount> availableSeats){
                cout<<"Ticket count is more than available seats! Try again";
            }
            else{
                for (int i=0; i<ticketcount; i++){
                    cout<<"Enter details for each passenger: "<<endl;
                    p[i].input();

                    if (p[i].age <0){
                        throw "Invalid age!";
                    }
                    if (p[i].age<5){
                        throw "Children below 5 not allowed to travel alone!";
                    }
                }
                availableSeats = availableSeats - ticketcount;
                cout<<"Tickets booked successfully!"<<endl;
                for (int i=0; i<ticketcount; i++){
                    cout<<"Passenger name: "<<p[i].name<<" age: "<<p[i].age<<endl;
                }
                cout<<"Remaining seats: "<<availableSeats;
            }
        
        }
        catch (const char* msg){
                cout<<msg<<endl;
            }
    }
};
int RailwayBooking::  availableSeats = 50;

int main(){
    RailwayBooking b;
    b.bookTickets();

}
