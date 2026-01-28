#include <iostream>
#include <cstring>
using namespace std;

class StudentRecord {
private:
    int rollNo;
    int numSubjects;
    float* marks;
    char* name;

public:
    StudentRecord(int r, const char* n, int s) {
        rollNo = r;
        numSubjects = s;

        name = new char[strlen(n) + 1];
        strcpy(name, n);

        marks = new float[numSubjects];
        for (int i = 0; i < numSubjects; i++)
            marks[i] = 0;
    }

    ~StudentRecord() {
        delete[] name;
        delete[] marks;
        cout << "Memory freed!" << endl;
    }

    void readMarks() {
        for (int i = 0; i < numSubjects; i++) {
            cout << "Enter marks for subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void showDetails() const {
        float total = 0;

        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;

        for (int i = 0; i < numSubjects; i++) {
            cout << "Marks of subject " << i + 1 << ": " << marks[i] << endl;
            total += marks[i];
        }

        cout << "Total: " << total << endl;
        cout << "Percentage: " << (total / numSubjects) << "%" << endl;
    }

    float getHighestMark() const {
        if (numSubjects <= 0)
            return -1;

        float max = marks[0];
        for (int i = 1; i < numSubjects; i++) {
            if (marks[i] > max)
                max = marks[i];
        }
        return max;
    }
};

int main() {
    StudentRecord* s1 = new StudentRecord(239, "Anoushka", 3);

    s1->readMarks();
    cout << "Highest Marks: " << s1->getHighestMark() << endl;
    s1->showDetails();

    delete s1;
    return 0;
}
