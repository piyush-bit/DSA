# write a program using nested if else to show that weather a roll number is belongs to ocmputer scince department if this true then also show that he has go t grade O

roll_number = int(input("enter the roll number of the student: "))
cgpa = float(input("enter the cgpa of the student: "))

if(roll_number >= 2302080000 and roll_number < 2302090000):
    if cgpa >= 9.0:
        print("student is eligible for O grade")
    else:
        print("student is not eligible for O grade")
else:
    print("student is not from computer science department")