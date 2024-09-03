// problem: https://leetcode.com/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {

        int left=0, right=sqrt(c);
        while(left<=right)
        {
            long long sq = (long long)left*left + (long long) right*right;
            if(sq>c)
                right--;
            else if(sq<c)
                left++;
            else
                return true;
        }
        return false;        
    }
};
