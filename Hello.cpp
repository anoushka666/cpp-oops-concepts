#include<iostream>
#include<string.h>
using namespace std;
class TaxDeductibles;
class Employee{
    public:
    int eid;
    string eName;
    double annualSalary;

    friend void Tax(Employee, TaxDeductibles);

};
class TaxDeductibles{
    public:
    int eid;
    double insurancePremium;
    double homeLoanInterest;


    friend void Tax(Employee, TaxDeductibles);
};
void Tax(Employee e1, TaxDeductibles t1){
    double deduction;
    double annualTax;

    if(e1.eid!= t1.eid){
        cout<<"Sorry! Unable to compute tax as the eid dont match"<<endl;
    }
    else{
        if(t1.insurancePremium>50000){
            t1.insurancePremium = 50000;
        }
        deduction =  t1.insurancePremium + t1.homeLoanInterest;
        cout<<"Your total deduction= "<<t1.insurancePremium<<" + "<<t1.homeLoanInterest<<" = "<<deduction<<endl;
        

        annualTax = 0.1* (e1.annualSalary - deduction);
        cout<<"Your Annual Tax = 10% of ("<<e1.annualSalary <<" - "<<deduction<<") = "<<annualTax<<endl;
    }

    }

int main(){
    Employee e1;
    cout<<"Enter employee details: "<<endl;
    cin>>e1.eid>>e1.eName>>e1.annualSalary;

    TaxDeductibles t1;
    cout<<"Enter Tax Deductibles: "<<endl;
    cin>>t1.eid>>t1.insurancePremium>>t1.homeLoanInterest;

    Tax(e1,t1);


}
