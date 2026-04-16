#include<iostream>
using namespace std;
template <class T>
void returnMaxPair(T a, T b, T c){
    T sum;
    if ((a+b)> (b+c) && (a+b)>(c+a)){
        sum = a+b;
    }
    else if ((b+c)> (a+b) && (b+c)>(a+c)){
        sum = b+c;
    }
    else {
        sum = a+c;
    }
    cout<<"Highest sum: "<<sum<<endl;
}
template <class T>
void findMinMax(T arr[], int size, T &minVal, T &maxVal){
    minVal = arr[0];
    maxVal = arr[0];

    for (int i=1; i<size; i++){
        if (arr[i]<minVal){
            minVal = arr[i];
        }
        if (arr[i]>maxVal){
            maxVal = arr[i];
        }
    }
    cout<<"Minimum value = "<<minVal<<endl;
    cout<<"Maximum value = "<<maxVal<<endl;
}
int main(){
    returnMaxPair(2,3,1);
    returnMaxPair(1.5, 3.5, 2.5);
    int arr1[] = {4,7,1,9,3};
    int minInt, maxInt;
    findMinMax(arr1, 5, minInt, maxInt);

}
