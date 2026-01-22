#include<iostream>
#include<string>
using namespace std;

class Wall{
    private:
    int length;
    int height;

    public:
    Wall(int l, int h){
        length = l;
        height = h;
    }
    Wall(const Wall &w){
        length = w.length;
        height = w.height;
    }

    int area(){
        return length*height;
    }
};
int main(){
    Wall w1(5,6);
    cout<<"Area is = "<<w1.area()<<endl;
    Wall w2(w1);
    cout<<"Area (copied) is = "<<w2.area()<<endl;


}
