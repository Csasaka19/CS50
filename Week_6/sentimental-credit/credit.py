def main():
    while True:
        number = input("Number: ")
        if number.isdigit():
            break
    
    number = str(number)
    
    num_1 = ((int(number) % 100)// 10) * 2
    num_2 = ((int(number) % 10000)// 1000 * 2)
    num_3 = ((int(number) % 1000000)// 100000 * 2)
    num_4 = ((int(number) % 100000000)// 10000000 * 2)
    num_5 = ((int(number) % 10000000000)// 1000000000 * 2)
    num_6 = ((int(number) % 1000000000000)// 100000000000 * 2)
    num_7 = ((int(number) % 100000000000000)// 10000000000000 * 2)
    num_8 = ((int(number) % 10000000000000000)// 1000000000000000 * 2)

    num_1 = (num_1 % 100 // 10) + (num_1 % 10)
    num_2 = (num_2 % 100 // 10) + (num_2 % 10)
    num_3 = (num_3 % 100 // 10) + (num_3 % 10)
    num_4 = (num_4 % 100 // 10) + (num_4 % 10)
    num_5 = (num_5 % 100 // 10) + (num_5 % 10)
    num_6 = (num_6 % 100 // 10) + (num_6 % 10)
    num_7 = (num_7 % 100 // 10) + (num_7 % 10)
    num_8 = (num_8 % 100 // 10) + (num_8 % 10)

    sum1 = num_1 + num_2 + num_3 + num_4 + num_5 + num_6 + num_7 + num_8

    num_9 = (int(number) % 10)
    num_10 = ((int(number) % 1000) // 100)
    num_11 = ((int(number) % 100000) // 10000)
    num_12 = ((int(number) % 10000000) // 1000000)
    num_13 = ((int(number) % 1000000000) // 100000000)
    num_14 = ((int(number) % 100000000000) // 10000000000)
    num_15 = ((int(number) % 10000000000000) // 1000000000000)
    num_16 = ((int(number) % 1000000000000000) // 100000000000000)

    sum2 = num_9 + num_10 + num_11 + num_12 + num_13 + num_14 + num_15 + num_16

    total_sum = sum1 + sum2

    if total_sum % 10 != 0:
        print("Invalid")
        return

    if len(number) == 15 and (number[:2] == "34" or number[:2] == "37"):
        print("AMEX")
    elif len(number) == 16 and (number[:2] == "51" or number[:2] == "52" or number[:2] == "53" or number[:2] == "54" or number[:2] == "55"):
        print("MASTERCARD")
    elif len(number) == 13 or len(number) == 16 and number[:1] == "4":
        print("VISA")
    else:
        print("Invalid")
        return

if __name__ == "__main__":
    main()