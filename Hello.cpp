#include<iostream>
using namespace std;
class Employee{
    private:
    int *id;
    string *name;


    public:
    int n;
    Employee(){
        cout<<"Enter number of employees: ";
        cin>>n;

        name = new string[n];
        id = new int[n];


        for (int i=0; i<n; i++){
            cout<<endl<<"Enter payroll ID for employee "<<i+1<<": ";
            cin>>id[i];
            cout<<"Enter employee name: ";
            cin>>name[i];}
            int high = id[0];
            int low = id[0];
        for (int i=1; i<n; i++){
            if(id[i]>high){
                high = id[i];
            }
            if (id[i]<low){
                low = id[i];
            }

        }

    cout<<endl<<"~~EMPLOYEE REGISTER~"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Payroll ID: "<<id[i]<<"\t"<<"Name: "<<name[i]<<endl;
    }

    int find;
    cout<<"Enter payroll ID to search: ";
    cin>>find;

    for (int i=0; i<n; i++){
        if (find==id[i]){
            cout<<"Employee found"<<endl;
            cout<<"Payroll ID: "<<id[i]<<"\t"<<"Name: "<<name[i];
        }

        }
    
    cout<<endl<<"Highest payroll ID: "<<high<<endl;
    cout<<endl<<"Lowest payroll ID: "<<low<<endl;
    }
    
    
~Employee(){
    delete[]id;
    delete[]name;
}

};
int main(){
    Employee e1;
}
