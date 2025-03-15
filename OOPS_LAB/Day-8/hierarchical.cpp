#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id, double sal) : name(n), employeeID(id), salary(sal) {}

    void displayDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }

    double calculateAnnualSalary() {
        return salary * 12;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int id, double sal, int team) : Employee(n, id, sal), teamSize(team) {}

    void displayManagerDetails() {
        displayDetails();
        cout << "Managing a team of: " << teamSize << " employees" << endl;
    }

    double calculateAnnualSalaryWithBonus() {
        return calculateAnnualSalary() + 5000;
    }
};

class Engineer : public Employee {
private:
    string specialization;

public:
    Engineer(string n, int id, double sal, string spec) : Employee(n, id, sal), specialization(spec) {}

    void displayEngineerDetails() {
        displayDetails();
        cout << "Specialization: " << specialization << endl;
    }

    double calculateAnnualSalaryWithOvertime() {
        return calculateAnnualSalary() + 3000;
    }
};

int main() {
    Manager manager1("Alice Johnson", 1001, 8000, 5);
    cout << "Manager Details:" << endl;
    manager1.displayManagerDetails();
    cout << "Annual Salary with Bonus: $" << manager1.calculateAnnualSalaryWithBonus() << endl;

    Engineer engineer1("Bob Smith", 1002, 7000, "Software Development");
    cout << "\nEngineer Details:" << endl;
    engineer1.displayEngineerDetails();
    cout << "Annual Salary with Overtime: $" << engineer1.calculateAnnualSalaryWithOvertime() << endl;

    return 0;
}

