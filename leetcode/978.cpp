// https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res1=1,res2=1;
        vector<int> inc(arr.size(),1), dec(arr.size(),1);
        for(int i=1;i<arr.size();i++)
        {
            if(i%2==0)
            {
                if(arr[i]>arr[i-1])
                    inc[i] = max(inc[i],1+inc[i-1]);
                if(arr[i]<arr[i-1])
                    dec[i]=max(dec[i],1+dec[i-1]);
            }
            else
            {
                if(arr[i]<arr[i-1])
                    inc[i] = max(inc[i],1+inc[i-1]);
                if(arr[i]>arr[i-1])
                    dec[i]=max(dec[i],1+dec[i-1]);
            }
            res1=max(res1,inc[i]);
            res2=max(res2,dec[i]);
        }

        return max(res1,res2);
    }
};

