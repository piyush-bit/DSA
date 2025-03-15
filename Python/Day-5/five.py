#wap to create a class representing a circle , include methods to calculateit's area and perimeter 

class circle:
    def __init__(self,r):
        self.r = r

    def area(self):
        return 3.14*self.r**2

    def perimeter(self):
        return 2*3.14*self.r


cir1 = circle(5)
print(cir1.area())
print(cir1.perimeter())


# write a program to impliment inheritance of the parent class university which contain multiple child claass of autonomus colleges 
# wap to create a class representing a shopincart , include metods for adding and removing items and calculatinga the total price 
# 