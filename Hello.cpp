#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class String{
    private:
    char *s;
    int size;

    public:
    //parameterized constructor
    String(const char *b){
        size = strlen(b);
        s = new char[size+1]; 
        //dynamic memory allocation
        //[size+1] for '/0'
        strcpy(s, b);
    }

    //copy constructor
    String(const String &obj){
        size = obj.size;
        s = new char[size+1];
        strcpy(s, obj.s);
    }

    //destructor
    ~String(){
        delete[] s;
    }

    void print(){
        cout<<"string = "<<s<<endl;
        cout<<"length = "<<size<<endl;
    }
};
int main(){
    String s1("Hello");
    s1.print();

    String s2 = s1;
    s2.print();


}
