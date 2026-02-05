#include <iostream>
using namespace std;

/* =======================
   Employee Class (Q4a)
   ======================= */
class Employee {
    int empID;
    float basicSalary;

public:
    // Default constructor
    Employee() {
        empID = 0;
        basicSalary = 0;
    }

    // Parameterized constructor
    Employee(int id, float sal) {
        empID = id;
        basicSalary = sal;
    }

    // Copy constructor
    Employee(Employee &e) {
        empID = e.empID;
        basicSalary = e.basicSalary;
    }

    // Friend declarations
    friend void calculateNetSalary(Employee);
    friend void transferEmployee(class Department &, class Department &);
};

/* =======================
   Payroll Logic (Q4b)
   ======================= */
void calculateNetSalary(Employee e) {
    float allowance = e.basicSalary * 0.20; // 20%
    float deduction = e.basicSalary * 0.10; // 10%
    float netSalary = e.basicSalary + allowance - deduction;

    cout << "\nEmployee ID: " << e.empID << endl;
    cout << "Basic Salary: " << e.basicSalary << endl;
    cout << "Allowance: " << allowance << endl;
    cout << "Deduction: " << deduction << endl;
    cout << "Net Salary: " << netSalary << endl;
}

/* =======================
   Department Class (Q4c)
   ======================= */
class Department {
    string deptName;
    int totalEmployees;

public:
    Department(string name = "", int count = 0) {
        deptName = name;
        totalEmployees = count;
    }

    friend void transferEmployee(Department &, Department &);

    void display() {
        cout << deptName << " Department Employees: "
             << totalEmployees << endl;
    }
};

/* Friend function for transfer */
void transferEmployee(Department &from, Department &to) {
    if (from.totalEmployees > 0) {
        from.totalEmployees--;
        to.totalEmployees++;
    }
}

/* =======================
   Main Function
   ======================= */
int main() {
    // Q4a: Constructor overloading
    Employee e1;
    Employee e2(101, 30000);
    Employee e3(e2);

    // Q4b: Net salary calculation
    calculateNetSalary(e2);

    // Q4c: Department transfer
    Department d1("IT", 5);
    Department d2("HR", 3);

    cout << "\nBefore Transfer:" << endl;
    d1.display();
    d2.display();

    transferEmployee(d1, d2);

    cout << "\nAfter Transfer:" << endl;
    d1.display();
    d2.display();

    return 0;
}
