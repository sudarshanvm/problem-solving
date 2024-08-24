# problem: https://leetcode.com/problems/largest-divisible-subset/
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        dp = [[n] for n in nums] #dp[i] : largest divisible subset starting at i
        res = []
        for i in reversed(range(len(nums))):
            for j in range(i+1,len(nums)):
                if nums[j] % nums[i] == 0:
                    temp = [nums[i]] + dp[j]
                    if len(temp) > len(dp[i]):
                        dp[i] = temp

            if len(dp[i]) > len(res):
                res = dp[i]

        return res
        
