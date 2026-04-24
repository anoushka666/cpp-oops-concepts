#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insertAtBeginning(Node* &head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node* &head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteAtBeginning(Node *head){
    if (head==NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main(){
    Node *head = NULL;
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 15);
    insertAtEnd(head, 20);

    display(head);
}
