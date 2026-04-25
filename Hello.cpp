#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector <int> v1;
    int n;
    cout<<"Enter size of vector: ";
    cin>>n;
    v1.resize(n);

    cout<<"Enter elements: ";
    for (int i=0; i<n; i++){
        cin>>v1[i];
    }

int index;
cout<<"Enter index you want to remove (0-4): ";
cin>>index;

v1.erase (v1.begin() + index);
cout<<"New vector: "<<endl;
for (int i=0; i<v1.size(); i++){
    cout<<v1[i]<<" ";
}

int value;
int index2;
cout<<"Enter value and index to inset: ";
cin>>value>>index2;

v1.insert(v1.begin()+ index2, value);
cout<<"New vector: "<<endl;
for (int i=0; i<v1.size(); i++){
    cout<<v1[i]<<" ";
}

cout<<endl<<"Ascending order: "<<endl;
sort(v1.begin(), v1.end());
cout<<"New vector: "<<endl;
for (int i=0; i<v1.size(); i++){
    cout<<v1[i]<<" ";
}

cout<<endl<<"Descending order: "<<endl;
sort(v1.begin(), v1.end(), greater<int>());
cout<<"New vector: "<<endl;
for (int i=0; i<v1.size(); i++){
    cout<<v1[i]<<" ";
}


}
