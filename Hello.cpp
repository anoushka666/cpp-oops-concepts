#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int operation(int *a, int *b){
    int x = *a;
    int y = *b;
    *a = x + y;
    *b = abs(x - y);
    return *a, *b;
}
int main(){
    int a, b;
    int *p1 = &a;
    int *p2 = &b;
    cin>>a>>b;
    operation(p1, p2); 
    cout<<a<<endl<<b;
}
