#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

const int SUBJECTS = 6;
const int TOTAL_SUBJECTS = SUBJECTS + 1;

struct Student {
    string name;
    int roll;
    float marks[SUBJECTS];
    int lecturesAttended;
    float sgpa;
};


float calculateSGPA(const Student &s, const float credits[SUBJECTS], int totalLectures, float attendanceWeight) {
    float totalWeightedScore = 0.0f;
    float totalCredits = 0.0f;


    for (int i = 0; i < SUBJECTS; i++) {
        totalWeightedScore += s.marks[i] * credits[i];
        totalCredits += credits[i];
    }

    float attendancePercent = (totalLectures > 0) ? (float)s.lecturesAttended / totalLectures * 100.0f : 0.0f;
    totalWeightedScore += attendancePercent * attendanceWeight;
    totalCredits += attendanceWeight;


    return (totalWeightedScore / totalCredits) / 10.0f;
}


void displayStudent(const Student &s) {
    cout << left << setw(15) << s.name
         << setw(10) << s.roll
         << setw(10) << fixed << setprecision(2) << s.sgpa << endl;
}


void searchAboveThreshold(const vector<Student> &students, float threshold) {
    cout << "\nStudents with SGPA above " << threshold << ":\n";
    for (const auto &s : students) {
        if (s.sgpa > threshold) displayStudent(s);
    }
}


void searchFailures(const vector<Student> &students) {
    cout << "\nStudents who failed in any subject:\n";
    for (const auto &s : students) {
        bool failed = false;
        for (float mark : s.marks) {
            if (mark < 40) { failed = true; break; }
        }
        if (failed) displayStudent(s);
    }
}


void highestInSubject(const vector<Student> &students, int subjectIndex) {
    if (subjectIndex < 0 || subjectIndex >= SUBJECTS) {
        cout << "Invalid subject index.\n";
        return;
    }
    float maxScore = -1;
    for (const auto &s : students) {
        if (s.marks[subjectIndex] > maxScore) {
            maxScore = s.marks[subjectIndex];
        }
    }
    cout << "\nHighest scorer(s) in Subject " << subjectIndex + 1 << ":\n";
    for (const auto &s : students) {
        if (s.marks[subjectIndex] == maxScore) displayStudent(s);
    }
}

int main() {
    int N, totalLectures;
    cout << "Enter number of students: ";
    cin >> N;
    cout << "Enter total number of lectures: ";
    cin >> totalLectures;

    vector<Student> students(N);
    float credits[SUBJECTS];
    cout << "Enter credit weight for each of the 6 subjects:\n";
    for (int i = 0; i < SUBJECTS; i++) {
        cin >> credits[i];
    }
    float attendanceWeight;
    cout << "Enter fixed weight for attendance: ";
    cin >> attendanceWeight;


    for (int i = 0; i < N; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].roll;
        cout << "Enter marks for 6 subjects: ";
        for (int j = 0; j < SUBJECTS; j++) {
            cin >> students[i].marks[j];
        }
        cout << "Lectures attended: ";
        cin >> students[i].lecturesAttended;


        students[i].sgpa = calculateSGPA(students[i], credits, totalLectures, attendanceWeight);
    }


    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.sgpa > b.sgpa;
    });


    cout << "\nRanked Students (by SGPA + Attendance):\n";
    cout << left << setw(15) << "Name" << setw(10) << "Roll" << setw(10) << "SGPA" << endl;
    for (const auto &s : students) {
        displayStudent(s);
    }


    float threshold;
    cout << "\nEnter SGPA threshold to search: ";
    cin >> threshold;
    searchAboveThreshold(students, threshold);

    searchFailures(students);

    int subjectIndex;
    cout << "\nEnter subject index (1-6) to find highest scorer: ";
    cin >> subjectIndex;
    highestInSubject(students, subjectIndex - 1);

    return 0;
}
