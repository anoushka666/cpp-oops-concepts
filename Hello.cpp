#include<iostream>
using namespace std;
int main(){
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;

    cout<<"Enter array index: ";
    cin>>index;

    try{
        //throw exception if array is out of bounds
        if (index<0 || index>4){
            throw "Invalid index! Try again";
        }

        cout<<"Enter numerator: ";
        cin>>numerator;
        cout<<"Enter denominator: ";
        cin>>denominator;

        //throw exception if denominator is 0 
        if (denominator==0){
            throw "Invalid denominator! Try again";
        }
        else{
        arr[index] = numerator/denominator;
        cout<<arr[index]<<endl;
        }
    }
    
    catch (const char *msg){
        cout<<msg<<endl;
    }
}
