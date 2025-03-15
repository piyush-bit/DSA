#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int registrationNumber;
    string name;
    float cgpa;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full!" << endl;
        return;
    }
    
    Student student;
    cout << "Enter registration number: ";
    cin >> student.registrationNumber;
    cin.ignore(); // to ignore the newline character after entering number
    cout << "Enter name: ";
    getline(cin, student.name);
    cout << "Enter CGPA: ";
    cin >> student.cgpa;
    students[studentCount++] = student;
    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "No student records found." << endl;
        return;
    }
    cout << "Student Information:" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << "Registration Number: " << students[i].registrationNumber << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "CGPA: " << students[i].cgpa << endl;
        cout << "---------------------------" << endl;
    }
}

void updateStudent() {
    int regNumber;
    cout << "Enter registration number of the student to update: ";
    cin >> regNumber;
    cin.ignore(); // to ignore the newline character after entering number

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].registrationNumber == regNumber) {
            found = true;
            cout << "Current Information:" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "CGPA: " << students[i].cgpa << endl;
            
            cout << "Enter new name (or press Enter to keep current): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                students[i].name = newName;
            }

            cout << "Enter new CGPA (or press Enter to keep current): ";
            string newCgpaStr;
            getline(cin, newCgpaStr);
            if (!newCgpaStr.empty()) {
                students[i].cgpa = stof(newCgpaStr);
            }

            cout << "Student information updated successfully!" << endl;
            return;
        }
    }
    if (!found) {
        cout << "Student not found with registration number " << regNumber << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Student Information System Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character after entering choice

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

