# bcd and lcf of two numbers 
def find_gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def find_lcm(a, b):
    return (a * b) // find_gcd(a, b)

def find_gcd_lcm(a, b):
    return find_gcd(a, b), find_lcm(a, b)


a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
print(find_gcd_lcm(a, b))
