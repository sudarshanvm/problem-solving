# problem: https://leetcode.com/contest/weekly-contest-412/problems/final-array-state-after-k-multiplication-operations-i/
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for i in range(k):
            min_value = min(nums)
            min_index = nums.index(min_value)

            nums[min_index] = nums[min_index] * multiplier

        return nums


