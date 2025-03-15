#Q.1
for i in range(1, 11):
    print(i)
#Q.2
start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))

for i in range(start, end + 1):
    if i % 2 == 0:
        print(i, end=" ")
# Q.3
n = int(input("Enter a number: "))
total_sum = sum(range(1, n + 1))
print(f"The sum of numbers from 1 to {n} is {total_sum}")
#Q.4
start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))

odd_sum = sum(i for i in range(start, end + 1) if i % 2 != 0)
print(f"The sum of all odd numbers between {start} and {end} is {odd_sum}")

# Q.5
n = int(input("Enter the number for the multiplication table: "))

for i in range(1, 11):
    print(f"{n} x {i} = {n * i}")

# Q.6
# Example list of numbers
numbers = [10, 20, 30, 40, 50]

# Displaying numbers using a for loop
for number in numbers:
    print(number)
