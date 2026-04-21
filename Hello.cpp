#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
int main(){
    //create nodes
    Node* head = new Node{2,nullptr};
    Node* second = new Node{3, nullptr};
    Node* third = new Node{4, nullptr};
    Node* fourth = new Node{5, nullptr};

    //link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    //print the linked list 
    Node* temp = head;
    while (temp!= nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl<<"After inserting 0 at the beginning"<<endl;

    //insert at the beginning 
    Node* n = new Node{1};
    n->next = head;
    head = n;

    //print the new linked list 
    Node* temp1 = head;
    while (temp1!= nullptr){
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
}
