# write a python to cheeck weather a citizen is senior citizen or not 

age = int(input("enter the age of the person: "))

if age < 18 :
    print("person is a minor")
elif age > 18 and age < 60:
    print("person is a citizen")
else:
    print("person is a senior citizen")
