def calculate_coins(cents):
    # Define the coin values
    coin_values = [25, 10, 5, 1]
    total_coins = 0

    for value in coin_values:
        while cents >= value:
            total_coins += 1
            cents -= value

    return total_coins

def main():
    # Prompt the user for change owed, in dollars (convert to cents)
    while True:
        try:
            dollars = input("Change owed: ")
            if dollars.strip() == "":
                raise ValueError("Input cannot be empty.")
            # Convert input to cents
            cents = int(float(dollars) * 100)
            if cents < 0:
                raise ValueError("Input cannot be negative.")
            break
        except ValueError as e:
            print(e)

    # Calculate the total number of coins
    total_coins = calculate_coins(cents)

    print(total_coins)

if __name__ == "__main__":
    main()
