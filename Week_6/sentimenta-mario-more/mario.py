while True:
    height = int(input("Height: "))
    if height >= 1 and height <= 8:
        break

for i in range(height):
    for n in range(height - i - 1):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for k in range(i + 1):
        print("#", end="")
    print()
