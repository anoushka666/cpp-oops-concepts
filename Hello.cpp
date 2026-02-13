#include<iostream>
#include<string>
using namespace std;
class Account{            //base class
    protected:   //private but accessible to child class
    int account_num;
    string holder_name;
    double balance;
    

    public:
    //initialize details
    Account(int a, string b, double c):account_num(a), holder_name(b), balance(c){}
    void deposit(double amount){
        balance = balance + amount;
        cout<<"New balance: "<<balance<<endl;
    }
    void withdraw(double amount){
        if (amount>balance){
            cout<<"Insufficient funds"<<endl;
        }
        else {
            balance = balance - amount;
            cout<<"New balance: "<<balance<<endl;
        }
    }
    void display() const{
        cout<<"Accout number: "<<account_num<<endl;
        cout<<"Holder name: "<<holder_name<<endl;
        cout<<"Balance: "<<balance<<endl;

    }
};

class SavingsAccount : public Account{
    private:
    double interest_rate;

    public:
    SavingsAccount(int a, string b, double c, double d):Account(a,b,c), interest_rate(d){};
    void apply_interest(){
        double interest = balance * (interest_rate/100);
        balance = balance + interest;
        cout<<"New balance: "<<balance<<endl;
    }
    void display() const{
        cout<<"Interest rate: "<<interest_rate<<"%"<<endl;
    }
};

class CurrentAccount : public Account{
    private:
    double overdraft_limit;

    public:
    CurrentAccount(int a, string b, double c, double d): Account(a,b,c), overdraft_limit(d){};
    void withdraw(double amount){
        if (amount > balance + overdraft_limit){
            cout<<"Withdrawal exceeds limit"<<endl;
        }
        else{
            balance = balance - amount;
            cout<<"New balance: "<<balance<<endl;
        }
    }
    void display() const{
        cout<<"Overdraft limit: "<<overdraft_limit<<endl;

    }
};
int main(){
    SavingsAccount s1(1001, "anoushka", 5000, 5);
    s1.Account::display();
    s1.display();
    
    s1.withdraw(20000);
    s1.apply_interest();

    cout<<endl;

    CurrentAccount c1(2001, "aana", 10000, 2000);
    c1.Account::display();
    c1.display();

    c1.withdraw(2000);
    return 0;
}
