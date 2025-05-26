# import os

# file_path = "file.txt"

# if os.path.exists(file_path):
#     os.remove(file_path)
# else:
#     with open(file_path, "w") as f:
#         f.write("Hello this is a file")

# write a program using file handling to check weather is exist or not if it is present then delete it else create it 
# write a program using file handling to check weather is exist or not if it is present then delete it else create it 
# write a program to demonstrate how to read data from a text file 
# write a program to demonstrate how to append content to a existing file 
# write a program to to check wearher a file is exoist or not if exist then use the method to create a fresh file 

f =open("file.txt", "a")
f.write("\n hello this is a new line")
f.close()

import os 

if not os.path.exists("file.txt"):
    with open("file.txt", "r") as f:
        print(f.read())
else:
    with open("freshfile.txt", "w") as f:
        f.write("Hello this is a file")
