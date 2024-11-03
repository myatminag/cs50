def print_hashes(i):
    # Print i+1 hashes (to match the 0-based indexing in the C code)
    print("#" * (i + 1), end="")

def main():
    # Get the height input from the user
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                break
            else:
                print("Please enter a number between 1 and 8.")
        except ValueError:
            print("Please enter a valid integer.")

    # Print the pyramid pattern
    for i in range(n):
        # Print the leading spaces
        print(" " * (n - i - 1), end="")

        # Print left hashes
        print_hashes(i)

        # Print the gap between the two sides of the pyramid
        print("  ", end="")

        # Print right hashes
        print_hashes(i)

        # Move to the next line
        print()

# Run the main function
if __name__ == "__main__":
    main()
