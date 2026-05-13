#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//reverse a string using stack
int main(){
    string str;
    cout<<"enter string: ";
    cin>>str;

    stack<char> s;
    //push all elements of string into stack 
    for (int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    //print stack 
    while(!s.empty()){
        cout<<s.top();
        s.pop();

    }
}
