//problem: https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=0, right=1, n=nums.size();

        if(nums.size()==0)
            return 0;

        double res=nums[0], resmin=nums[0],resmax = nums[0];

        while(right<n)
        {
            double cur = nums[right];
            double prod1 = (double) resmax * cur;
            double prod2 = (double) resmin * cur;
            resmax = max(cur, max(prod1, prod2));
            resmin = min(cur, min(prod1, prod2));

            res = max(res, resmax);
            right++;
        }

        return res;
    }
};




//--------


//https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int maxProduct(vector<int>& nums) {
        int mxsf=nums[0], mnsf=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int cur1 = nums[i]*mxsf;
            int cur2 = nums[i]*mnsf;
            int tempmax=max(nums[i],max(cur1,cur2));
            int tempmin=min(nums[i],min(cur1,cur2));
            
            mxsf=tempmax;
            mnsf=tempmin;
            res=max(mxsf,res);
        }
        return res;
    }
};
