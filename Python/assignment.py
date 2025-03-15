# 1. Print first 10 natural numbers using a loop
for i in range(1, 11):
    print(i)

# 2. Print all even numbers in a given range
def print_even(start, end):
    for i in range(start, end + 1):
        if i % 2 == 0:
            print(i)

# 3. Sum of numbers from 1 to N
def sum_n(n):
    return sum(range(1, n + 1))

# 4. Sum of odd numbers in a range
def sum_odd(start, end):
    return sum(i for i in range(start, end + 1) if i % 2 != 0)

# 5. Multiplication table of a number
def multiplication_table(n):
    for i in range(1, 11):
        print(f"{n} x {i} = {n * i}")

# 6. Display list elements using a loop
def print_list(lst):
    for item in lst:
        print(item)

# 7. Count digits in a number
def count_digits(n):
    return len(str(abs(n)))

# 8. Check if a string is a palindrome
def is_palindrome(s):
    return s == s[::-1]

# 9. Reverse a word
def reverse_word(word):
    return word[::-1]

# 10. Check if a number is Armstrong
def is_armstrong(n):
    digits = [int(d) for d in str(n)]
    return sum(d ** len(digits) for d in digits) == n

# 11. Count even and odd numbers in a series
def count_even_odd(lst):
    even = sum(1 for i in lst if i % 2 == 0)
    odd = len(lst) - even
    return even, odd

# 12. Display non-prime numbers in a range
def non_primes(start, end):
    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True
    return [i for i in range(start, end + 1) if not is_prime(i)]

# 13. Fibonacci series up to 50
def fibonacci():
    a, b = 0, 1
    while a <= 50:
        print(a, end=" ")
        a, b = b, a + b
    print()

# 14. Factorial of a number
def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

# 15. Count digits and letters in a string
def count_digits_letters(s):
    digits = sum(c.isdigit() for c in s)
    letters = sum(c.isalpha() for c in s)
    return digits, letters

# 16. Print integers from 1 to 25
print(list(range(1, 26)))

# 17. Check password validity
def check_password(pwd):
    return len(pwd) >= 8 and any(c.isdigit() for c in pwd) and any(c.isalpha() for c in pwd)

# 18. Convert month name to days
def month_to_days(month):
    days_in_month = {
        "January": 31, "February": 28, "March": 31, "April": 30,
        "May": 31, "June": 30, "July": 31, "August": 31,
        "September": 30, "October": 31, "November": 30, "December": 31
    }
    return days_in_month.get(month, "Invalid month")


# Main function to execute all programs
def main():
    print("1. First 10 natural numbers:", list(range(1, 11)))
    
    print_even(1, 20)
    
    print("3. Sum of numbers from 1 to 10:", sum_n(10))
    
    print("4. Sum of odd numbers from 1 to 20:", sum_odd(1, 20))
    
    multiplication_table(5)
    
    print_list([1, 2, 3, 4, 5])
    
    print("7. Digits in number 12345:", count_digits(12345))
    
    print("8. 'racecar' is palindrome?", is_palindrome("racecar"))
    
    print("9. Reverse of 'hello':", reverse_word("hello"))
    
    print("10. 153 is Armstrong?", is_armstrong(153))
    
    even, odd = count_even_odd([1, 2, 3, 4, 5, 6])
    print(f"11. Even count: {even}, Odd count: {odd}")
    
    print("12. Non-prime numbers from 1 to 20:", non_primes(1, 20))
    
    print("13. Fibonacci series up to 50:", fibonacci())
    
    print("14. Factorial of 5:", factorial(5))
    
    digits, letters = count_digits_letters("Hello123")
    print(f"15. Digits: {digits}, Letters: {letters}")
    
    print("16. Integers from 1 to 25:", list(range(1, 26)))
    
    print("17. Is 'Secure123' a valid password?", check_password("Secure123"))
    
    print("18. Days in February:", month_to_days("February"))

# Run the main function
if __name__ == "__main__":
    main()