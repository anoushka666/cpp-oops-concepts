#include <iostream>
using namespace std;

class MyVector {
    int* arr;
    int size;
    int capacity;

public:
  
    MyVector() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

    void Push(int data) {
        if (size == capacity)
            resize();
        arr[size++] = data;
    }

    void Push(int data, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }

        if (size == capacity)
            resize();

        for (int i = size; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = data;
        size++;
    }

    int Get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return -1;
        }
        return arr[index];
    }

    void Pop() {
        if (size == 0) {
            cout << "Vector empty\n";
            return;
        }
        size--;
    }

    int Size() {
        return size;
    }

    int GetCapacity() {
        return capacity;
    }

    void Print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~MyVector() {
        delete[] arr;
    }
};

int main() {
    MyVector v;

    v.Push(10);
    v.Push(20);
    v.Push(30);
    v.Push(15, 1); 

    v.Print(); 

    cout << "Element at 2: " << v.Get(2) << endl;
    cout << "Size: " << v.Size() << endl;
    cout << "Capacity: " << v.GetCapacity() << endl;

    v.Pop();
    v.Print();

    return 0;
}
