#include<iostream>
using namespace std;
class PetrolPump{
    public:
    int petrol;
    int distance;
};

int circularTour( PetrolPump p[], int n){
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for (int i=0; i<n; i++){
        balance = balance + p[i].petrol - p[i].distance;

        //cannot continue 
        if (balance<0){
            deficit = deficit + balance;
            start = i+1;
            balance = 0;
        }
    }
    //check if tour is possible 
    if (balance + deficit >=0){
        return start;
    }
    //if impossible 
    return -1;
}
int main(){
    PetrolPump p[] = {
        {6,4}, {3,6}, {7,3}
    };
    int n = 3;
    cout<<"Start from pump index: "<<circularTour(p, n);
}
