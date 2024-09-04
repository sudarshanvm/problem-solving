// prpoblem: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size(),res=0;
        vector<int> left(n,0),right(n,0);
        left[0]=arr[0];
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1]+arr[i],arr[i]);

        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1]+arr[i],arr[i]);

        res = *max_element(left.begin(),left.end());
        for(int i=1;i<n-1;i++)
            res=max(res, left[i-1]+right[i+1]);

        return res;
    }
};


