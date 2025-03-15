#write a program to check that wheather a variable contains string or complex data type

a = "hello"
b = 10 + 5j 

if type(a) == str:
    print("a is a string")
elif type(b) == complex:
    print("b is a complex number")
