#include<iostream>
using namespace std;
class Product{
    private:
    double costPrice;
    double markedPrice;
    double discount;
    double sellingPrice;
    static int count;

    public:
    Product(){
        cout<<"Enter product details: "<<endl;
        cin>>costPrice>>markedPrice>>discount;
        sellingPrice = markedPrice * (1-discount/100);
    
    if (sellingPrice> costPrice){
        count++;
        cout<<"Selling price: "<<sellingPrice<<endl;
    }
}
    
    static int getcount(){
        return count;
    }
    bool isfeasible(){
        return sellingPrice > costPrice;
    }
};
int Product::count = 0;

int main(){
    Product *product = new Product[3];
    int count = 0;
    for (int i=0; i<3; i++){
        if(product[i].isfeasible()){
            count++;
        }

    }
    cout<<"Number of feasible products= "<<count;
}
