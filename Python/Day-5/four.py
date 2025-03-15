
    #wap a program using constructor to show the details of vssut and also include a method that display performance year wise 

class University:
    def __init__(self):
        self.id = input("enter the id of the student: ")
        self.name = input("enter the name of the student: ")
        self.esstablishment = input("enter the esstablishment year  of the university: ")
        self.naac = input("Enter naac score : ")
        self.placement = input("Enter placement rate : ")

    def display(self):
        print(f"ID: {self.id}")
        print(f"Name: {self.name}")
        print(f"Esstablishment Year: {self.esstablishment}")
        print(f"NAAC Score: {self.naac}")
        print(f"Placement Rate: {self.placement}")

univ = University()
univ.display()


#wap to create a class representing a circle , include methods to calculateit's area and perimeter 
