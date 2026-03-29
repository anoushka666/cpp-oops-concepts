#include<iostream>
#include<string>
using namespace std;
class Ship{
    protected:
    string name;
    int fuelCapacity;
    double valuation;
    string owningCompany;
    double insurancePremium;

    public:
    Ship(string n, int f, double v, string o){
        name = n;
        fuelCapacity = f;
        valuation = v;
        owningCompany = o;
        
    }
};
class CruiseShip: public Ship{
    public:
    int pools;
    int passengers;
    double foodStorage;

    CruiseShip(string n, int f, double v, string o, int c1, int c2, double c3): Ship(n,f,v,o){
        passengers = c1;
        pools = c2;
        foodStorage = c3;
    }

    void calulcateInsurancePremium(){
        insurancePremium = (double)(valuation + fuelCapacity + foodStorage)/ (passengers*pools);
    }
    void displayDetails(){
        cout<<"Ship name: "<<name<<endl;
        cout<<"Ship type: Cruise Ship"<<endl;
        cout<<"Insurance Premium: "<<insurancePremium<<endl;
    }
};
class CargoCarrier: public Ship{
    public:
    int crew;
    int riskyZones;
    double inflammables;

    CargoCarrier(string n, int f, double v, string o, int d1, int d2, double d3): Ship(n,f,v,o){
        crew = d1;
        riskyZones = d2;
        inflammables = d3;
    }
    void calulcateInsurancePremium(){
        insurancePremium = (double)((valuation + fuelCapacity)* riskyZones + inflammables)/ (crew*1000);
    }
    void displayDetails(){
        cout<<"Ship name: "<<name<<endl;
        cout<<"Ship type: Cargo Carrier"<<endl;
        cout<<"Insurance Premium: "<<insurancePremium<<endl;
    }

};

int main() {
    CruiseShip cs("Ocean Star", 5000, 2000000, "BlueWave", 200, 4, 1500.5);
    cs.calulcateInsurancePremium();
    cs.displayDetails();

    cout<<endl;

   CargoCarrier cc("Cargo King", 8000, 3000000, "SeaTrans", 50, 3, 2500.75);
    cc.calulcateInsurancePremium();
    cc.displayDetails();

    return 0;
}
