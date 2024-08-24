# problem: https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        dp = [1] * len(pairs) #dp[i] : length of longest chain starting at i
        pairs.sort()
        res = 0
        for i in reversed(range(len(pairs))):
            p1 = pairs[i]
            for j in range(i+1,len(pairs)):
                p2 = pairs[j]
                if p1[1] < p2[0]:
                    temp = 1 + dp[j]
                    if temp > dp[i]:
                        dp[i] = temp

            if dp[i] > res:
                res = dp[i]

        return res

        
