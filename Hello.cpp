#include<iostream>
using namespace std;

class TransportUnit{
public:
    int load;
    int distance;
    int efficiency;

    void inputTransport(){
        cout<<"Enter load: ";
        cin>>load;
        cout<<"Enter distance: ";
        cin>>distance;
        efficiency = load / distance;
    }
};

class NetworkRelay{
public:
    int bandwidth;
    int signal;

    void inputRelay(int d){
        cout<<"Enter bandwidth: ";
        cin>>bandwidth;
        signal = bandwidth / d;
    }
};

class AutonomousRig : public TransportUnit, public NetworkRelay{
public:
    void inputRig(){
        cout<<"\n--- Enter details for Autonomous Rig ---\n";
        inputTransport();              
        inputRelay(distance);          
    }

    void display(){
        cout<<"Efficiency: "<<efficiency<<endl;
        cout<<"Signal: "<<signal<<endl;
    }
};


bool operator>(const AutonomousRig &a1, const AutonomousRig &a2){
    return (a1.efficiency + a1.signal) > (a2.efficiency + a2.signal);
}

int main(){
    cout<<"Evaluating fleet:\n";

    AutonomousRig a1, a2;

    cout<<"\nRig A:";
    a1.inputRig();

    cout<<"\nRig B:";
    a2.inputRig();

    cout<<"\n--- Results ---\n";
    a1.display();
    a2.display();

    if(a1 > a2){
        cout<<"Rig A is the superior asset\n";
    } else {
        cout<<"Rig B is the superior asset\n";
    }

    return 0;
}
