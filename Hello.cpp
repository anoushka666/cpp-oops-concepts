#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Task{
    public:
    string name;
    int duration;
    
    Task(string n, int d){
        name = n;
        duration = d;
    }
};

//function to stimulate CPU scheduling 
void stimulateCPU(queue<Task> q, int t){
    while (!q.empty()){
        Task current = q.front();
        q.pop();    //removes the task from queue

        //if task completes 
        if (current.duration<=t){
            cout<<"Task "<<current.name<<" executed and completed"<<endl;
        }
        //if task needs more time
        else{
            current.duration = current.duration - t;
            cout<<"Task "<<current.name<<" executed for "<<t<<" units, ";
            cout<<current.duration<<" units remaining"<<endl;

        //reinsert into queue
        q.push(current);
        }
    }
}
int main(){
    int n;
    cout<<"Enter number of tasks: ";
    cin>>n;

    queue<Task> q;
    for (int i=0; i<n; i++){
        string name;
        int duration;

        cout<<"Enter task name: ";
        cin>>name;
        cout<<"Enter task duration: ";
        cin>>duration;
        
        q.push(Task(name, duration));
    }
    int t;
    cout<<"Enter time slice: ";
    cin>>t;

    stimulateCPU(q,t);
}
