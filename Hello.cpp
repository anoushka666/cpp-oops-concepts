#include<iostream>
#include<cstring>
using namespace std;
class Box{
    private:
    int length;
    int breadth;
    int height;

    public:
    Box(int l, int b, int h){
        length = l;
        breadth = b;
        height = h;
    }
    void display(){
        cout<<"Length: "<<length<<endl;
        cout<<"Breadth: "<<breadth<<endl;
        cout<<"Height: "<<height<<endl;
    }

    friend void calculateVol(Box b);

};
void calculateVol(Box b){
    cout<<"Volume: "<<b.breadth*b.height*b.length<<endl;

}
int main(){
    Box b1(10,5,10);
    b1.display();
    calculateVol(b1);
return 0;
    //this is a weak assigner's question
}
