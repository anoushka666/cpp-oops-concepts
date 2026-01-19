#include<iostream>
#include<string>
using namespace std;
class Bank{
    private:
    string name;
    int ac_no;
    char type;   
    double balance;

    public:
    void details(string n, int a, char t, double b){
        name = n;
        ac_no = a;
        type = t;
        balance = b;
    }
    
    void deposit(int amount){
    
        balance += amount;
    }

    void withdraw(int amount){
    
        if ((balance-amount)>1000){
            balance-= amount;
        }
        else{
            cout<<"Cannot withdraw"<<endl;
        }
    }

    void display(){
        cout<<"Name of account holder = "<<name<<endl;
        cout<<"Account number = "<<ac_no<<endl;
        cout<<"Account type = "<<type<<endl;
        cout<<"Balances = "<<balance;
    }
};
int main(){
    Bank b[10];
    b[0].details ("mark", 9191, 'S', 5000);
    b[0].deposit(500);
    b[0].withdraw(500);
    b[0].display();
}
