//problem: https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int res=0;
        int r=0;
        while(x)
        {
            r=x%10;
            x/=10;
            if(res>INT_MAX/10 || (res==INT_MAX/10 && r > 7))
                return 0;
            if(res<INT_MIN/10 || (res==INT_MIN/10 && r < -8))
                return 0;
            res=res*10+r;
        }
    
        return res;
    }
};
