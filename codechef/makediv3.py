# cook your dish here
t = int(input())

for i in range(0, t):
    n = int(input())

    num = pow(10, n - 1) + 2

    if n == 1:
        print("3")
    else:
        num = "3"  # Corrected indentation here
        for i in range(0, n - 2):
            num += "0"

        num += "3"

        print(num)
