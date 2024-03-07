while True:
    height_input = input("Height: ")
    if height_input.isdigit():
        height = int(height_input)
        if height >= 1 and height <= 8:
            break
    print("Invalid input. Please enter a numeric value between 1 and 8.")

for i in range(height):
    for n in range(height - i - 1):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for k in range(i + 1):
        print("#", end="")
    print()
