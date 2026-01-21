#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", 
    "eight", "nine"};

    if (n<=9){
        cout<<words[n];

    }
    else{
        cout<<"Number is greater than 9";
    }
}
