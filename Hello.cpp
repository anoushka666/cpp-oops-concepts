#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
int main(){
    //create nodes 
    Node* head = new Node{2,nullptr};
    Node* second = new Node{3,nullptr};
    Node* third = new Node{4, nullptr};
    Node* fourth = new Node{5, nullptr};

    //link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    
    //print linked list 
    Node *temp = head;
    while (temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
