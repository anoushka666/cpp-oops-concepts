#include<iostream>
#include<string>
using namespace std;
class EWallet{
    private:
    int userId;
    string userName;
    double currentBalance;

    public:
    EWallet(){
        cout<<"Enter user ID: ";
        cin>>userId;
        cout<<"Enter user name: ";
        cin>>userName;
        cout<<"Enter current balance: ";
        cin>>currentBalance;
        if(currentBalance<0){
            currentBalance = 0;
        }
    }

    void addMoney(double amount){
        currentBalance = currentBalance + amount;
        if(currentBalance<0){
            currentBalance = 0;
        }
    }

    void display(){
        cout<<"User ID: "<<userId<<endl;
        cout<<"User name: "<<userName<<endl;
        cout<<"Balance: "<<currentBalance<<endl;
    }

    void transfer(EWallet e1, double amount){
        currentBalance = currentBalance - amount;
        e1.currentBalance = e1.currentBalance + amount;
        if(currentBalance<0){
            currentBalance = 0;
        }
    }
    void operator-(double amount) {
        if (amount <= currentBalance) {
            currentBalance -= amount;
        } else {
            cout << "Insufficient balance!\n";
        }
    }


    friend ostream& operator <<(ostream& out, const EWallet& e1);
};

    ostream& operator <<(ostream& out, const EWallet& e1){
        out<<"User name: "<<e1.userName<<endl;
        out<<"User ID: "<<e1.userId<<endl;
        out<<"Balance: "<<e1.currentBalance<<endl;
        return out;


    }
int main(){
    EWallet e1;
    EWallet e2;

    e1.addMoney(4000);
    e1 - 1000;
    cout<<e1;
    
    e1.transfer(e2, 300);
    cout<<e2;
    cout<<e1;
}
