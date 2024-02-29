# Assumption the input will be in dollars
def main():
    # Prompt for dollars
    dollars = get_dollars()
    # Convert dollars to cents
    cents = dollars * 100
    
    # Calculate the number of coins
    quarters_count = quarters(cents)
    cents = cents - (quarters_count * 25)
    
    dimes_count = dimes(cents)
    cents = cents - (dimes_count * 10)
    
    nickels_count = nickels(cents)
    cents = cents - (nickels_count * 5)
    
    pennies_count = pennies(cents)
    cents = cents - (pennies_count * 1)
    
    coins = quarters_count + dimes_count + nickels_count + pennies_count
    print(coins)
    
def get_dollars():
    while True:
        try:
            dollars = float(input("Change: "))
            if dollars >= 0:
                return dollars
        except ValueError:
            print("Invalid input")

def quarters(cents):
   return cents // 25
    
def dimes(cents):
    return cents // 10

def nickels(cents):
    return cents // 5

def pennies(cents):
   return cents // 1

if __name__ == "__main__":
    main()