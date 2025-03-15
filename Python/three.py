def add(a, b):
    """This function adds two numbers"""
    return a + b


def subtract(a, b):
    """This function subtracts two numbers"""
    return a - b


def multiply(a, b):
    """This function multiplies two numbers"""
    return a * b


def divide(a, b):
    """This function divides two numbers"""
    return a / b


def calculator():
    print("Simple Calculator")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")

    choice = input("Enter your choice: ")

    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    if choice == "1":
        print(num1, "+", num2, "=", add(num1, num2))

    elif choice == "2":
        print(num1, "-", num2, "=", subtract(num1, num2))

    elif choice == "3":
        print(num1, "*", num2, "=", multiply(num1, num2))

    elif choice == "4":
        print(num1, "/", num2, "=", divide(num1, num2))

    else:
        print("Invalid choice")

calculator()



def simple_interest(principal, rate, time):
    """
        This function calculates the simple interest.

        Args:
            principal (float): The principal amount.
            rate (float): The interest rate.
            time (float): The time in years.

        Returns:
            float: The simple interest.
    """
    return (principal * rate * time) / 100

def compound_interest(principal, rate, time):
    """
        This function calculates the compound interest.

        Args:
            principal (float): The principal amount.
            rate (float): The interest rate.
            time (float): The time in years.

        Returns:
            float: The compound interest.
    """
    return principal * (1 + rate / 100) ** time - principal


