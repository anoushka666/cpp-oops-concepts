#include<iostream>
using namespace std;
class Forex;
class Equity{
    protected:
    int buyPrice;
    int CMP;
    int quantity;

    public:
    Equity(){
        cout<<"Enter details: ";
        cin>>buyPrice>>CMP>>quantity;
    }
    void displayE(){
        cout<<"Equity: "<<endl;
        cout<<"Buying price: "<<buyPrice<<endl;
        cout<<"CMP: "<<CMP<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
    friend void Compare(Equity, Forex);
};
class Forex{
    protected:
    int quotePrice;
    int basePrice;
    int lotSize;
    int noofLots;

    public:
    Forex(){
        cout<<"Enter details: ";
        cin>>quotePrice>>basePrice>>lotSize>>noofLots;
    }
    void displayF(){
        cout<<"Forex: "<<endl;
        cout<<"Quote Price: "<<quotePrice<<endl;
        cout<<"Base Price: "<<basePrice<<endl;
        cout<<"Lot Size: "<<lotSize<<endl;
        cout<<"Noof Lots: "<<noofLots<<endl;
    }

    friend void Compare(Equity, Forex);
};
void Compare(Equity e1, Forex f1){
    int yieldEquity = ((e1.buyPrice- e1.CMP)*e1.quantity)/e1.buyPrice;
    int yieldForex = ((f1.quotePrice - f1.basePrice)*f1.lotSize*f1.noofLots)/(f1.quotePrice+ f1.basePrice);
    if(yieldEquity> yieldForex){
        cout<<"Equity is the better financial instrument"<<endl;
        e1.displayE();
    }
    else{
        cout<<"Forex is the better financial instrument"<<endl;
        f1.displayF();
    }
     
}
int main(){
    Equity e1;
    Forex f1;
    Compare(e1,f1);
}
