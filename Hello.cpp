#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;
int main(){

    string guess;
    string words[3] = {"gold", "water", "pillow"};
    string hints[3] = {"metal used for jewellery", "essential liquid", "gives comfort to head while sleeping"};
    for (int i=0; i<3; i++){
        int attempts = 6;
        cout<<"Hint: "<<hints[i]<<endl;
        for (int j=0; j<words[i].length(); j++){
            cout<<"_ ";
        }
        cout<<endl;
       

        while (attempts>0){
            cout<<"Guess the word!"<<endl;
            cin>>guess;
            if (guess==words[i]){
                cout<<"Correct!"<<endl;
                break;
            }
            else {
                attempts--;
                cout<<"Incorrect! Attempts left: "<<attempts<<endl;
            }
        }
        if (attempts==0){
            cout<<"Game over! The correct word was: "<<words[i]<<endl;
        }
        }
    }

