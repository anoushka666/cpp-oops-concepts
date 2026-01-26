#include<iostream>
#include<string>
using namespace std;
class Bank{
    private: 
    string name;
    int acc_no;
    double balance;

    public:
    void assign(string n, int a, double b){
        name = n;
        acc_no = a;
        balance = b;
    }
    void deposit(double amount){
        balance+= amount;
    }
    void withdraw(double amount){
        if(balance<amount){
            cout<<"Not sufficient money"<<endl;
        }
        else {
            balance-= amount;
        }
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};
int main(){
    Bank b1;
    b1.assign("Anoushka", 239, 1000);
    b1.deposit(500);
    b1.withdraw(5000);
    b1.display();
}
