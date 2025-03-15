# wap to check the number enterd by user is prime or not 
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
# wap to show all the prime numbers between range of two  numbers and display the sum of all this prime number 

start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))

prime_sum = sum(i for i in range(start, end + 1) if is_prime(i))
print(f"The sum of all prime numbers between {start} and {end} is {prime_sum}")

# wap to check whether a number is armstrong or not

# n = int(input("Enter a number: "))
# sum = 0
# temp = n
# while temp > 0:
#     digit = temp % 10
#     sum += digit ** 3
#     temp //= 10
# if n == sum:
#     print(n, "is an Armstrong number")
# else:
#     print(n, "is not an Armstrong number")

#wap to display 
# i. all the even numbers and there sum 
# ii. all the odd numbers and their sum
# iii. display the sum of all with range 1 to 100 

# even_sum = sum(range(2, 101, 2))
# odd_sum = sum(range(1, 100, 2))
# print(f"The sum of all even numbers between 1 and 100 is {even_sum}")
# print(f"The sum of all odd numbers between 1 and 100 is {odd_sum}")
# total_sum = even_sum + odd_sum
# print(f"The sum of all numbers between 1 and 100 is {total_sum}")


# #wap a program to check wheather the year is leap year or not 

# year = int(input("Enter a year: "))
# if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
#     print(year, "is a leap year")
# else:
#     print(year, "is not a leap year")

# # wap suing membership operator and check wheather an element belongs to or part of an array or not 

# arr = [1, 2, 3, 4, 5]
# print(3 in arr)


