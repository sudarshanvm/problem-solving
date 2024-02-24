//https://leetcode.com/contest/biweekly-contest-124/problems/maximum-number-of-operations-with-the-same-score-i/
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ops=1,res=1;
        //unordered_map<int,int>m;
        int lastsum=nums[0]+nums[1],sum=0;
        for(int i=2;i<nums.size()-1;i+=2)
        {
            int sum = nums[i]+nums[i+1];
            if(sum==lastsum)
            {
                ops++;
                res=max(res,ops);
            }
           
            else
                return ops;
            
            
            //m[sum]++;
            lastsum=sum;
        }
        // int res=0;
        // for(auto entry:m)
        // {
        //     res=max(res,entry.second);
        // }
        return res;
    }
};