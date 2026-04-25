#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
//reverse a linked list 
Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev;
}

//find middle node
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


//Floyd's algorithm 
bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (slow==fast){
            return true;
        }
      
        }
        return false;
}
int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; //to make cycle

    if(hasCycle(head)){
        cout<<"Cycle detected"<<endl;
    }
    else{
        cout<<"No cycle detected"<<endl;
    }
}
