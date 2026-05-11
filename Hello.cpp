#include<iostream>
using namespace std;

//include cases when the linked list is empty 

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head = tail = NULL;
    }

    void print(){
        Node* temp = head;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = NULL;
            tail = newNode;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if (head = NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front(){
        if (head==NULL){
            cout<<"Linked list is empty";
        }
        else{
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back(){
        if (head==NULL){
            cout<<"Linked list is empty";
        }
        else{
            Node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
    }

};
int main(){
    List l1;
    l1.push_front(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.pop_back();
    l1.print();
}
