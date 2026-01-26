#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements: "<<endl;
    int sum=0;
    for (int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<"Sum of elements: "<<sum;

}
