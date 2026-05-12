#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = orev = NULL;
    }
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = tail = NULL;
    }
bool isPalindrome(){
    Node* start = head;
    Node* end = tail;

    while (start !=end && start->prev != end){
        if (start-> data != end->data){
            return false;
        }
        start = start->next;
        end = end->next;
    }
    return true;
}
};
int main(){


}
