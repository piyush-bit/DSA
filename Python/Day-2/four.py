# wap using logic operator to show taht if cgpa is more tahn 9 and attendace is more than 90% the student will qualify to the IIT 

cgpa = float(input("enter the cgpa of the student: "))
attendance = float(input("enter the attendance of the student: "))

if cgpa > 9 and attendance > 90:
    print("student is eligible for IIT")
elif cgpa > 9 or attendance > 90:
    print("student is eligible for NIT")
elif not cgpa > 9 and not attendance > 90:
    print("student is not eligible for VSSUT")
else:
    print("student is not eligible for IIT")