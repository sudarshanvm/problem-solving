//problem: https://leetcode.com/problems/fraction-addition-and-subtraction/
import re
import math
class Solution:

    def get_lcm(self,a,b):
        gcd = math.gcd(a,b)
        return (a*b) // gcd

    def fractionAddition(self, exp: str) -> str:
        parts = re.split(r'(?=[+-])', exp)
        parts = [part for part in parts if part]
        print(parts)

        nums = []
        dens = []

        lcm = 1
        for part in parts:
            temp = part.split('/')
            nums.append(int(temp[0]))
            dens.append(int(temp[1]))
            lcm =  self.get_lcm(lcm, int(temp[1]))
        
        res = 0
        for i in range(0,len(nums)):
            numr = nums[i]
            denr = dens[i]
            m = lcm // denr
            numr *= m
            res += numr

        gcd = math.gcd(res,lcm)
        res //= gcd
        lcm //= gcd

        return str(res) + "/" + str(lcm)



        
