# https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-24
class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        def lcp(a:str,b:str) -> int:
            res = min(len(a),len(b))
            for i in range(res):
                if a[i]!=b[i]:
                    return i
            return res

        res = 0
        a1 = [str(a) for a in arr1]
        a2 = [str(a) for a in arr2]
        a1.sort()
        a2.sort()

        for i in range(len(a1)):
            idx = bisect_right(a2,a1[i])
            print(idx)

            if idx < len(a2):
                res = max(res, lcp(a2[idx],a1[i]))
            if idx>0:
                res = max(res,lcp(a2[idx-1],a1[i]))
        
        return res
