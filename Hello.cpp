#include<iostream>
#include<cstdlib>  //for rand()
#include<ctime>    //for srand()
using namespace std;

int flip(){
    return rand()%2;  //returns 0 or 1
}
int main(){
    int heads = 0;
    int tails = 0;
    srand(time(0));
    for (int i=0; i<10 ; i++){
        int result = flip();
        if(result==1){
            cout<<"Heads"<<endl;
            heads++;
        }
        else{
            cout<<"Tails"<<endl;
            tails++;
        }
    }
    cout<<"Total heads = "<<heads<<endl;
    cout<<"Total tails = "<<tails<<endl;
}
