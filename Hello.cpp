#include<iostream>
#include<new>
using namespace std;

class Throw{
public:
    Throw(){
        int n;
        cin >> n;

        try{
            int *arr = new int[n];

            for(int i = 0; i < n; i++){
                cin >> arr[i];

                if(arr[i] < 0){
                    throw "Exception: A is negative";
                }
            }

            delete[] arr;
        }
        catch(bad_alloc&){
            cout << "Not enough memory" << endl;
        }
        catch(const char *msg){
            cout << msg << endl;
        }
    }
};

int main(){
    Throw t1;
}
