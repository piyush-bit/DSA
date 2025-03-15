# wap to check the number enterd by user is prime or not 
# def is_prime(n):
#     if n <= 1:
#         return False
#     for i in range(2, int(n**0.5) + 1):
#         if n % i == 0:
#             return False
#     return True
# # wap to show all the prime numbers between range of two  numbers and display the sum of all this prime number 

# start = int(input("Enter the start of the range: "))
# end = int(input("Enter the end of the range: "))

# prime_sum = sum(i for i in range(start, end + 1) if is_prime(i))
# print(f"The sum of all prime numbers between {start} and {end} is {prime_sum}")