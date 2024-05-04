from math import gcd

def precompute_gcd(n, m):
    gcd_values = [[0] * (m + 1) for _ in range(n + 1)]
    for a in range(1, n + 1):
        for b in range(1, m + 1):
            gcd_values[a][b] = gcd(a, b)
    return gcd_values

def count_ordered_pairs(n, m, gcd_values):
    count = 0
    for a in range(1, n + 1):
        for b in range(1, m + 1):
            if (a + b) % (b * gcd_values[a][b]) == 0:
                count += 1
    return count


t = int(input())


for _ in range(t):
    
    n, m = map(int, input().split())
    gcd_values = precompute_gcd(n,m)

    
    
    print(count_ordered_pairs(n, m,gcd_values))
