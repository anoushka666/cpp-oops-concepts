#include <iostream>
#include <cstring>
using namespace std;

class TravelPlan {
private:
    long PlanCode;
    char Place[20];
    int Number_of_travellers;
    int Number_of_buses;

public:
    // Constructor with initial values
    TravelPlan() {
        PlanCode = 1001;
        strcpy(Place, "Agra");
        Number_of_travellers = 5;
        Number_of_buses = 1;
    }

    // Function to accept new plan details
    void NewPlan() {
        cout << "Enter Plan Code: ";
        cin >> PlanCode;

        cout << "Enter Place: ";
        cin >> Place;

        cout << "Enter Number of Travellers: ";
        cin >> Number_of_travellers;

        if (Number_of_travellers < 20)
            Number_of_buses = 1;
        else if (Number_of_travellers >= 20 && Number_of_travellers < 40)
            Number_of_buses = 2;
        else
            Number_of_buses = 3;
    }

    // Function to display plan details
    void ShowPlan() {
        cout << "\nPlan Code: " << PlanCode << endl;
        cout << "Place: " << Place << endl;
        cout << "Number of Travellers: " << Number_of_travellers << endl;
        cout << "Number of Buses: " << Number_of_buses << endl;
    }
};

int main() {
    TravelPlan T;
    T.NewPlan();
    T.ShowPlan();
    return 0;
}
