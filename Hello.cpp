//template to swap 
#include<iostream>
using namespace std;
template <class T>
void swapValues(T &a, T &b){
    T temp;
    temp = a;    
    a = b;
    b = temp;

}
int main(){
    int i = 4;
    int j = 5;
    cout<<"Before swapping, i = "<<i<<" j = "<<j<<endl;
    swapValues(i,j);
    cout<<"After swapping, i = "<<i<<" j = "<<j<<endl;
    
    
}
