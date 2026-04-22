#include<iostream>
using namespace std;
template <class T>
class MyVector{
    private:
    T* arr;        //dynamic array 
    int capacity;  //total capacity
    int current;   //current size

    public:
    MyVector(int size = 2){   //constructor
        capacity = size;
        current = 0;
        arr = new T[capacity];

    }
    ~MyVector(){               //destructor
        delete[] arr;
    }
    //functions
    int size(){
        return capacity;
    }

    void push_back( T data){
        if (current ==capacity){
            capacity = capacity*2;
            T* newarr = new T[capacity];

            for (int i=0; i<capacity; i++){
                newarr[i] = arr[i];

            }
            delete[] arr;
            arr = newarr;
            
        }
        arr[current] = data;
        current++;
    }

    void pop_back(){
        if (current==0){
            cout<<"Vector is empty!"<<endl;
        }
        current--;
    }
    void display(){
        for (int i=0; i<current; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MyVector <int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.display();

    v.pop_back();
    v.display();
    cout<<"Size: "<<v.size()<<endl;
}
