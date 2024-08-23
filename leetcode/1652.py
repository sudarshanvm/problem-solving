# problem: https://leetcode.com/problems/defuse-the-bomb/
class Solution:
    def solve(self, res, code, n, k):
        left = 0
        right = 1
        sum = 0
        while(left<n):
            while(right-left-1 < k):
                sum += code[right]
                right += 1
            print(sum)
            res[left] = sum
            sum += code[right]
            sum -= code[left+1]
            left += 1
            right += 1

        return res

    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        code = code+code
        res = [0] * n

        if k==0:
            return [0] * n

        elif k>0:
            res = self.solve(res,code,n,k)

        else:
            res = self.solve(res,code[::-1],n,-k)
            res = res[::-1]

        return res



