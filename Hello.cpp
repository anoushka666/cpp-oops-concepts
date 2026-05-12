#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKelements(queue<int>& q, int k){

    stack<int> s;

    // Put first k elements into stack
    for(int i=0; i<k; i++){

        s.push(q.front());
        q.pop();
    }

    // Put reversed elements back into queue
    while(!s.empty()){

        q.push(s.top());
        s.pop();
    }

    // Move remaining elements to back
    int remaining = q.size() - k;

    for(int i=0; i<remaining; i++){

        q.push(q.front());
        q.pop();
    }
}

int main(){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;

    reverseKelements(q, k);

    // Print queue
    while(!q.empty()){

        cout << q.front() << " ";
        q.pop();
    }
}
