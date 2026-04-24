//to find second smallest number in an arry
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int smallest = INT_MAX;
    int secondsmallest = INT_MAX;

    for (int i=0; i<n; i++){
        if (arr[i]<smallest){
            secondsmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<secondsmallest){
            secondsmallest = arr[i];
        }
    }
    cout<<"Second smallest element: "<<secondsmallest;

}
