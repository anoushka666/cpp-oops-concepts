#include<iostream>
#include<string>
using namespace std;
class Ship{
    protected:
    string name;
    int fuel_capacity;
    double valuation;
    string owning_company;
    double insurance_premium;

    public:

    virtual void computeInsurance() = 0; //pure virtual function
    void getDataShip(){
        cout<<"Enter details of ship: ";
        cin>>name>>fuel_capacity>>valuation>>owning_company>>insurance_premium;
    }

    void display(){
        cout<<"\nShip Name: "<<name<<endl;
        cout<<"Fuel Capacity: "<<fuel_capacity<<endl;
        cout<<"Valuation: "<<valuation<<endl;
        cout<<"Owning Company: "<<owning_company<<endl;
        cout<<"Insurance Premium: "<<insurance_premium<<endl;
    
    }


};
class CruiseShip: public Ship{
    protected: 
    int passengers;
    int pools;
    double food_storage;

    public:
    void computeInsurance(){
        insurance_premium = (valuation + fuel_capacity + food_storage)/ (passengers*pools);
        cout<<"Insurance premium: "<<insurance_premium;
    }

    void getData(){
        getDataShip();
        cout<<"Enter additional details of cruise ship: ";
        cin>>passengers>>pools>>food_storage;
    }
    

};

class CargoShip: public Ship{
    protected: 
    int crew;
    int zones;
    double inflammable;

    public:
    void computeInsurance(){
        insurance_premium = ((valuation+ fuel_capacity)*zones+inflammable)/(crew*1000);
        cout<<"Insurance premium: "<<insurance_premium;
    }

    void getData(){
        void getDataShip();
        cout<<"Enter additional details of cargo ship: ";
        cin>>crew>>zones>>inflammable;
    }
};

int main(){
    CruiseShip s1;
    s1.getData();
    s1.computeInsurance();
    s1.display();

}
