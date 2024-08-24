# problem : https://leetcode.com/problems/find-the-closest-palindrome/?envType=daily-question&envId=2024-08-24

def solve(a,s):
    n = int(s)
    res = float("inf")
    mindiff = float("inf")

    a = [int(st) for st in a]

    a.sort()
    for num in a:
        print(num)
        temp = abs(num-n)
        if(temp<mindiff and temp>0):
            res = num
            mindiff = temp

    return str(res)

class Solution:
    def nearestPalindromic(self, s: str) -> str:

        n = len(s)
        half_len = n // 2
        
        if int(s) < 10:
            return str(int(s)-1)

        a = []
        s_half = ""
        if n%2==0:
            s_half = s[:half_len]
            s_half_minus_one = str(int(s_half)-1)
            s_half_plus_one = str(int(s_half)+1)
            s_pow_minus_one = str(pow(10,n-1)-1)
            s_pow_plus_one = str(pow(10,n-1)+1)


            a.append(s_half + s_half[::-1])
            a.append(s_half_minus_one + s_half_minus_one[::-1])
            a.append(s_half_plus_one + s_half_plus_one[::-1])
            a.append(s_pow_minus_one)
            a.append(s_pow_plus_one)
            a.append(str(pow(10,n)+1))
            a.append(str(pow(10,n)-1))

        else:
            s_half = s[:half_len+1]
            s_half_minus_one = str(int(s_half)-1)
            s_half_plus_one = str(int(s_half)+1)
            s_pow_minus_one = str(pow(10,n-1)-1)
            s_pow_plus_one = str(pow(10,n-1)+1)

            a.append(s_half[:-1]  + s_half[::-1])
            a.append(s_half_minus_one[:-1]  + s_half_minus_one[::-1])
            a.append(s_half_plus_one[:-1]  + s_half_plus_one[::-1])
            a.append(s_pow_minus_one)
            a.append(s_pow_plus_one)
            a.append(str(pow(10,n)+1))
            a.append(str(pow(10,n)-1))
        
        return solve(a,s)
