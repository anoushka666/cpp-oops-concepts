#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of students: ";
    cin>>n;

    float *cgpa = new float[n];

    for (int i=0; i<n; i++){
        cout<<"Enter cgpa of student "<<i+1<<": ";
        cin>>cgpa[i];
    }

    for (int i=0; i<n; i++){
        cout<<"CGPA of student "<<i+1<<": "<<cgpa[i]<<endl;
    }

    delete[] cgpa;
}
