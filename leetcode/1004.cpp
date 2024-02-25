//problem: https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:

    //sliding window
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size();
        int z=0;
        int left=0, right=0, res=0;
        while(right<n)
        {
            if(nums[right]==0)
                z++;
            while(z>k)
            {
                if(nums[left]==0)
                    z--;
                left++;
            }
            if(z<=k)
                res=max(res,right-left+1);
            right++;
        }

        return res;
    }

    //brute force
    // int longestOnes(vector<int>& nums, int k) {
        

    //     int res=0;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         int z=0;
    //         for(int j=i;j<n;j++)
    //         {
    //             if(nums[j]==0)
    //                 z++;
    //             if(z<=k)
    //             {
    //                 cout<<"j-i+1: "<<j<<"-"<<i<<"+"<<1<<endl;
    //                 res=max(res,j-i+1);
    //             }
    //         }
    //     }

    //     return res;
    // }

};