#include<iostream>
using namespace std;
class Box{
    public:
    int boxes;
    int choice;
    int *capacity;

    Box(){
        cout<<"Enter number of boxes: ";
        cin>>boxes;
        capacity = new int[boxes];

        for (int i=0; i<boxes; i++){
            cout<<"Box "<<i+1<<": "<<endl;
            cout<<"1. Default capacity(50)"<<endl;
            cout<<"2. Custom choice"<<endl;
            cout<<"Enter choice: ";
            cin>>choice;

            if (choice==1){
                capacity[i] = 50;
            }
            if(choice==2){
                cout<<"Enter custom capacity: ";
                cin>>capacity[i];
            }
        }
    
  
        int total=0;
        int maxbox=0;
        int max = capacity[0];
        cout<<endl<<"Box capacities: "<<endl;
        for (int i=0; i<boxes; i++){
            cout<<"Box "<<i+1<<": "<<capacity[i]<<endl;
            total += capacity[i];
            if(capacity[i]>max){
                max = capacity[i];
                maxbox = i;
            }
        }
        cout<<"Total capacity: "<<total<<endl;;
        cout<<"Average box capacity: "<<(float)total/boxes<<endl;
        cout<<"Box with maximum capacity: "<<"Box "<<maxbox+1<<"("<<max<<")"<<endl;
    }

    ~Box(){
        delete[]capacity;
        cout<<"Memory released successfully";
    }
};

int main(){
    Box b1;
    
}
