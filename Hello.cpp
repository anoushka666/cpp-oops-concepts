#include <iostream>
using namespace std;

class Employee {
    int empID;
    float basicSalary;

public:
    
    Employee() {
        empID = 0;
        basicSalary = 0;
    }

    Employee(int id, float sal) {
        empID = id;
        basicSalary = sal;
    }

    Employee(Employee &e) {
        empID = e.empID;
        basicSalary = e.basicSalary;
    }

   
    friend void calculateNetSalary(Employee);
    friend void transferEmployee(class Department &, class Department &);
};


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

void transferEmployee(Department &from, Department &to) {
    if (from.totalEmployees > 0) {
        from.totalEmployees--;
        to.totalEmployees++;
    }
}


int main() {
    
    Employee e1;
    Employee e2(101, 30000);
    Employee e3(e2);


    calculateNetSalary(e2);


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

