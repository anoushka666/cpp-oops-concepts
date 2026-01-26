#include<iostream>
using namespace std;
int main(){
    int A[3] = {10, 100, 200};
    int *ptr = A;

    cout<<"After increment operator: "<<endl;
    for (int i=0; i<3; i++){
        cout<<"Address of var["<<i<<"] "<<ptr<<endl;
        cout<<"Value of var["<<i<<"]" <<*ptr<<endl;
        ptr++;
    }

    cout<<"After decrement operator: "<<endl;
    for (int i=2; i>=0; i--){
        cout<<"Address of var["<<i<<"] "<<ptr<<endl;
        cout<<"Value of var["<<i<<"]" <<*ptr<<endl;
        ptr--;
    }


}
