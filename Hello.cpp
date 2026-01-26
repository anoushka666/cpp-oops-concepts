#include<iostream>
using namespace std;
class Vector{
    private:
    int size;
    float v[100];

    public:
    void assign(int n){
        size = n;
        cout<<"Enter "<<size<<" elements: "<<endl;
        for (int i=0; i<size; i++){
            cin>>v[i];
        }
    }

    void add(int s){
        for (int i=0; i<size; i++){
            v[i]+=s;
        }
    }
    void multiply(int s){
        for (int i=0; i<size; i++){
            v[i]*=s;
        }
    }
    void display(){
        for (int i=0; i<size; i++){
            cout<<v[i]<<" ";
        }
    }
  
};
int main(){
    Vector v1;
    v1.assign(3);
    cout<<endl<<"Vector elements: "<<endl;
    v1.display();
    v1.add(10);
    cout<<endl<<"Updated Vector elements: "<<endl;
    v1.display();
    v1.multiply(5);
    cout<<endl<<"Updated Vector elements: "<<endl;
    v1.display();

}
