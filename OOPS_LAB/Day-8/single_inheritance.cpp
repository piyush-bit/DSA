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

int main() {
    Manager manager1("John Doe", 1001, 7000, 5);

    manager1.displayManagerDetails();

    cout << "Annual Salary with Bonus: $" << manager1.calculateAnnualSalaryWithBonus() << endl;

    return 0;
}

