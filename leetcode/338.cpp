
//problem: https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int count = 0;
            int num = i;
            while(num)
            {
                if(num%2!=0)
                    count++;
                num/=2;
            }
            res[i]=count;
        }
        return res;
    }
};