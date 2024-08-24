# problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1]*n
        res = [1]*n

        max_size = 0
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    temp = 1 + dp[j]
                    if temp > dp[i]:
                        dp[i] = temp
                        res[i] = res[j]
                    elif temp == dp[i]:
                        res[i] += res[j]
            max_size = max(max_size,dp[i])

        count = 0
        for i in range(n):
            if dp[i] == max_size:
                count += res[i]

        return count 
                


        
