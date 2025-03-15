class Parent2:
    def greet(self):
        print("Hello from Parent2")

class Parent1:
    def greet(self):
        print("Hello from Parent1")


class Child(Parent2,Parent1):
    pass

child = Child()
child.greet()

