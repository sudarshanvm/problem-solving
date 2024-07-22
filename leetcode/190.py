//problem: https://leetcode.com/problems/reverse-bits/
class Solution:
    def reverseBits(self, n: int) -> int:
        s = bin(n)[2:]
        res = 0

        if len(s) < 32:
            temp = '0' * (32-len(s))
            s = temp+s
        for i in range(0,len(s)):
            if s[i]=='1':
                res += pow(2,i)
            
        return res
