#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class BankAccount{
    private:
    char *accountHolder;
    double balance;

    public:
//parametrized constructor
    BankAccount(const char *a, double b){
        balance = b;
        accountHolder = new char[strlen(a) +1];
        strcpy(accountHolder, a);
    }
//copy constructor
    BankAccount(const BankAccount &b1){
        balance = b1.balance;
        accountHolder = new char(strlen(b1.accountHolder)+1);
        strcpy(accountHolder, b1.accountHolder);
    }
//destructor
    ~BankAccount(){
        delete[] accountHolder;
    }
//member function to print details
    void print(){
        cout<<"Name: "<<accountHolder<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};
int main(){
    BankAccount b1("Anoushka", 50000);
    b1.print();

    BankAccount b2 = b1;
    b2.print();
}
