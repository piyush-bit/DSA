# list =[peach , watermellon ,mango , apple ,] which element in list contain character g in it

list = ["peach" , "watermellon" , "mango" , "apple" ,]
# for i in list:
#     if "g" in i:
#         print(i)


print([x for x in list if "g" in x])


# wap to check weather the element in the contains vowels or not and store all the elements that contain vowel in a list 
vowels = "aeiouAEIOU"
v = [x for x in list if any(char in vowels for char in x)]

print(v)

print(type(list))


