//second largest element of an array 
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
   cout<<"Enter rotating index: ";
   cin>>k;

    k = k%n;
    int temp[n];
    for (int i=0; i<n; i++){
        temp[(i+k)%n] = arr[i];
    }
    for (int i=0; i<n; i++){
        cout<<temp[i]<<" ";
    }


}
