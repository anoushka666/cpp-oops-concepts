#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int query;
    cin>>query;

    
    int **arr = new int*[n]; //n arrays
    int *sizes = new int [n];

    for (int i=0; i<n; i++){
        cin>>sizes[i];
        arr[i] = new int[sizes[i]];

        for (int j=0; j<sizes[i]; j++){
            cin>>arr[i][j];
        }
    }
    
    for (int i=0; i<query; i++){
        int x,y;
        cin>>x>>y;
        cout<<arr[x][y]<<endl;
    
    }
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] sizes;
}
