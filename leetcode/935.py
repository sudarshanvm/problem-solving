#problem: https://leetcode.com/problems/knight-dialer/
class Solution:
    def knightDialer(self, n: int) -> int:
        # i,j-> i-2,j+1 | i+2,j+1 | i-2,j-1 | i+2,j-1 |i-1,j-2 | i+1,j-2 | i-1,j+2 | i+1, j+2
        a = [1]*10
        mod = 10**9+7

        jumps = [
            [4,6], #0
            [6,8], #1
            [7,9], #2
            [4,8], #3
            [3,9,0], #4
            [], #5
            [1,7,0], #6
            [2,6], #7
            [1,3], #8
            [2,4], #9
        ]

        for i in range(n-1):
            temp = [0]*10
            for j in range(len(jumps)):
                for k in range(len(jumps[j])):
                    temp[jumps[j][k]] += a[j]
                    temp[jumps[j][k]] %= mod
            a = temp

        res = 0
        for i in a:
            res += i
            res %= mod

        return res

