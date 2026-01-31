#include<iostream>
using namespace std;
class Matrix{
    private:
    int rows;
    int cols;

    public:
    
    Matrix(int r, int c){
        rows = r;
        cols = c;
        int **arr = new int*[rows];
        for (int i=0; i<rows; i++){
            arr[i] = new int[cols];

        }
    

        cout<<"Enter elements of the matrix: ";
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                cin>>arr[i][j];
            }
        }

        cout<<"Matrix: "<<endl;
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }

    

};
int main(){
    Matrix m1(3,3);
}
