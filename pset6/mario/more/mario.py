from cs50 import get_int

while True:
    height = get_int("Enter a positive number: ")

    if height >= 1 and height <= 8:
        break

for row in range(height):
        print(" " * (height - row - 1), end = "")
        print("#" * (row + 1), end = "")
        print("  ", end = "")
        print("#" * (row + 1))
