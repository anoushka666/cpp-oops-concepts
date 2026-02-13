#include<iostream>
using namespace std;
class Vector{
    private:
    double x;
    double y;

    public:
    void setData(){
        cout<<"Enter x and y coordinate: ";
        cin>>x>>y;
        cout<<endl;
    }
    Vector operator* (double t){
        Vector temp;
        temp.x = x*t;
        temp.y = y*t;
        return temp;
    }
    Vector operator + (Vector V){
        Vector temp;
        temp.x = x + V.x;
        temp.y = y + V.y;
        return temp;
    }

    void display(){
        if(y>=0){
            cout<<x<<" i  + "<<y<<" j"<<endl;
        }
        else{
            cout<<x<<" i  - "<<y<<" j"<<endl;
        }
    }   

};
int main(){
    Vector P, V, D;
    double t;
    P.setData();
    V.setData();
    cout<<"Enter time: ";
    cin>>t;

    D = P+(V*t);
    cout<<"Final position of boat: "<<endl;
    D.display();  
}
