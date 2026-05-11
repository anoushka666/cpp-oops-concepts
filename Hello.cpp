#include<iostream>
#include<vector>
using namespace std;

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

    //to input values into list
    void push_back(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    //to print linked list
    void print(){
        Node* temp = head;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    //to reverse the content (values) of a list 
    void reverseContent(){
        vector<int> arr;
        Node* temp = head;

        //store data in vector 
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        temp = head;
        int i = arr.size() - 1;

        //put data in reverse order
        while (temp!=NULL){
            temp->data = arr[i];
            i--;
            temp = temp->next;
        }
    }

    void reverseLinkedlist(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        head = prev;
    }
};
int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    cout<<"Original linked list: "<<endl;
    l1.print();
    cout<<endl;

    cout<<"Reversal of content of linked list: "<<endl;
    l1.reverseContent();
    l1.print();
    cout<<endl;

    cout<<"Reversal of linked list: "<<endl;
    l1.reverseLinkedlist();
    l1.print();
}
