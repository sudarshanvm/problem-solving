def count_flips(s):
    flips = 0
    prev_char = None
    
    for char in s:
        if char == prev_char:
            flips += 1
        prev_char = '0' if prev_char == '1' else '1'  # Toggle the previous character
    
    return flips

# Main function to handle input and output
def main():
    # Read the number of test cases
    t = int(input().strip())
    
    # Iterate through each test case
    for _ in range(t):
        # Read input for each test case
        n = int(input().strip())
        s = input().strip()
        
        # Count flips needed to make the string alternating
        flips = count_flips(s)
        
        # Output the minimum number of flips
        print(flips)

# Run the main function
if __name__ == "__main__":
    main()

