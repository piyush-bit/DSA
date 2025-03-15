class Employee:
    def about(self):
        self.name = input("enter the name of the employee: ")
        self.id = int(input("enter the id of the employee: "))
        self.salary = int(input("enter the salary of the employee: "))
        self.position = input("enter the position of the employee: ")

    def display(self):
        print(f"Name: {self.name}")
        print(f"ID: {self.id}")
        print(f"Salary: {self.salary}")
        print(f"Position: {self.position}")




class Student:
    def about(self):
        self.id = input("enter the id of the student: ")
        self.name = input("enter the name of the student: ")
        self.cgpa = float(input("enter the cgpa of the student: "))
    
    def display(self):
        print(f"ID: {self.id}")
        print(f"Name: {self.name}")
        print(f"CGPA: {self.cgpa}")

class Faculty:
    def about(self):
        self.id = input("enter the id of the faculty: ")
        self.name = input("enter the name of the faculty: ")
        self.salary = int(input("enter the salary of the faculty: "))
        self.position = input("enter the position of the faculty: ")
        self.teaching_subject = input("enter the teaching subject of the faculty: ")
        self.no_of_experience = int(input("enter the no of experience of the faculty: "))

    def display(self):
        print(f"ID: {self.id}")
        print(f"Name: {self.name}")
        print(f"Salary: {self.salary}")
        print(f"Position: {self.position}")
        print(f"Teaching Subject: {self.teaching_subject}")
        print(f"No of Experience: {self.no_of_experience}")
        

fac = Faculty()
fac.about()
fac.display()


#wap a program using constructor to show the details of vssut and also include a method that display performance year wise 