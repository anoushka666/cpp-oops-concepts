#include<iostream>
#include<set>
using namespace std;
int maxSockonTable(int arr[], int size){
    set<int> table;
    int current = 0;
    int maximum = 0;

    for (int i=0; i<size; i++){
        //first sock
        if (table.find(arr[i])== table.end()){
            table.insert(arr[i]);
            current++;
        }
        //pair found
        else{
            table.erase(arr[i]);
            current--;

        }
        if (current>maximum){
            maximum = current;
        }
    }
    return maximum;
}
int main(){
    int arr[] = {1,2,1,3,2,3};
    int size = 6;
    cout<<"Maximum socks on the table: "<<maxSockonTable(arr, size);
}
