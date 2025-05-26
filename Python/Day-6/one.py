# wap to implemnet oops of a class system whcih contains a child class chips if th e system are in the range of 70k -100k then dont be affordanble if below 70k and above 50k it is perfect but rest are not upto the mark so stor eall the affordable , perfect and rest systems in three different new list so that a user can easily identify which sytem he want to choose 

class System:
    def __init__(self, name, price):
        self.name = name
        self.price = price

class Chips(System):
    def __init__(self, name, price):
        super().__init__(name, price)

    def categorize_system(self):
        if 70000 <= self.price <= 100000:
            return "not_affordable"
        elif 50000 < self.price < 70000:
            return "perfect"
        else:
            return "not_up_to_mark"


systems = [
    Chips("System A", 40000),
    Chips("System B", 60000),
    Chips("System C", 70000),
    Chips("System D", 50000),
    Chips("System E", 112000),
    Chips("System F", 64000),
]


not_affordable = []
perfect = []
not_up_to_mark = []

for system in systems:
    category = system.categorize_system()
    if category == "not_affordable":
        not_affordable.append(system)
    elif category == "perfect":
        perfect.append(system)
    else:
        not_up_to_mark.append(system)


print("Not Affordable Systems:")
for sys in affordable:
    print(f"{sys.name} - ₹{sys.price}")

print("\nPerfect Systems:")
for sys in perfect:
    print(f"{sys.name} - ₹{sys.price}")

print("\nNot Up to the Mark Systems:")
for sys in not_up_to_mark:
    print(f"{sys.name} - ₹{sys.price}")
