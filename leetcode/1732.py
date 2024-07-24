# problem: https://leetcode.com/problems/find-the-highest-altitude

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        sum=0
        max=0
        for i in gain:
            sum = sum+i
            if(max< sum):
                max = sum
        return max
