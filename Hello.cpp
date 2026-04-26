#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

// ---------------- EXCEPTIONS ----------------
class NoSlotAvailableException : public exception {
public:
    const char* what() const throw() {
        return "No parking slots available!";
    }
};

class InvalidTicketException : public exception {
public:
    const char* what() const throw() {
        return "Invalid Ticket!";
    }
};

class OverstayException : public exception {
public:
    const char* what() const throw() {
        return "Overstay detected! Fine applied.";
    }
};

// ---------------- VEHICLE ----------------
class Vehicle {
public:
    string vehicleNumber;
    string type;

    Vehicle(string num = "", string t = "") {
        vehicleNumber = num;
        type = t;
    }

    bool operator==(const Vehicle& v) {
        return vehicleNumber == v.vehicleNumber;
    }
};

// ---------------- PARKING SLOT ----------------
class ParkingSlot {
public:
    int slotID;
    string size;
    bool isOccupied;

    ParkingSlot(int id, string s) {
        slotID = id;
        size = s;
        isOccupied = false;
    }
};

// ---------------- TICKET ----------------
class Ticket {
public:
    int ticketID;
    string vehicleNumber;
    time_t entryTime;

    Ticket(int id, string v) {
        ticketID = id;
        vehicleNumber = v;
        entryTime = time(0);
    }

    double calculateBill() {
        time_t exitTime = time(0);
        double hours = difftime(exitTime, entryTime) / 3600.0;
        if(hours < 1) hours = 1;
        return hours * 50; // ₹50/hour
    }
};

// ---------------- LINKED LIST ----------------
struct Node {
    Vehicle v;
    Node* next;

    Node(Vehicle vehicle) {
        v = vehicle;
        next = NULL;
    }
};

// ---------------- TEMPLATE FUNCTIONS ----------------
template<typename T>
int searchRecord(vector<T>& arr, T key) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}

template<typename T>
void sortRecords(vector<T>& arr) {
    sort(arr.begin(), arr.end());
}

// ---------------- PARKING SYSTEM ----------------
class ParkingSystem {
private:
    Node* head;
    vector<ParkingSlot> slots;
    queue<Vehicle> waitingQueue;
    stack<Vehicle> exitStack;
    int ticketCounter;

public:
    ParkingSystem() {
        head = NULL;
        ticketCounter = 1;

        // Create 3 slots
        slots.push_back(ParkingSlot(1, "small"));
        slots.push_back(ParkingSlot(2, "medium"));
        slots.push_back(ParkingSlot(3, "large"));
    }

    // Add to linked list
    void addVehicle(Vehicle v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }

    // Remove from linked list
    void removeVehicle(string num) {
        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL) {
            if(temp->v.vehicleNumber == num) {
                if(prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // Allocate slot
    int allocateSlot(string type) {
        for(auto &slot : slots) {
            if(!slot.isOccupied && slot.size == type) {
                slot.isOccupied = true;
                return slot.slotID;
            }
        }
        throw NoSlotAvailableException();
    }

    // Park vehicle
    void parkVehicle(Vehicle v) {
        try {
            int slotID = allocateSlot(v.type);
            addVehicle(v);
            cout << "Vehicle parked at slot " << slotID << endl;
        }
        catch(NoSlotAvailableException &e) {
            cout << e.what() << endl;
            waitingQueue.push(v);
        }
    }

    // Exit vehicle
    void exitVehicle(string num) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->v.vehicleNumber == num) {
                Ticket t(ticketCounter++, num);
                double bill = t.calculateBill();

                cout << "Bill: Rs " << bill << endl;

                exitStack.push(temp->v);
                removeVehicle(num);

                return;
            }
            temp = temp->next;
        }

        throw InvalidTicketException();
    }

    void displayAvailableSlots() {
        for(auto slot : slots) {
            if(!slot.isOccupied)
                cout << "Slot " << slot.slotID << " available\n";
        }
    }
};

// ---------------- MAIN ----------------
int main() {
    ParkingSystem ps;

    Vehicle v1("DL01AB1234", "small");
    Vehicle v2("DL02CD5678", "medium");
    Vehicle v3("DL03EF9999", "small");

    ps.parkVehicle(v1);
    ps.parkVehicle(v2);
    ps.parkVehicle(v3);

    ps.displayAvailableSlots();

    try {
        ps.exitVehicle("DL01AB1234");
    } catch(exception &e) {
        cout << e.what();
    }

    return 0;
}
