//problem statement : https://leetcode.com/problems/maximum-distance-in-arrays/description/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // for each array, we need to find the max element from remaining arrays and min element from current array and find the diff and compare with result to get the maximum difference. so at max we need to keep track of two maximum numbers 

        int firstmax=INT_MIN, secondmax=INT_MIN, res=INT_MIN;
        for(auto a:arrays)
        {
            int ele = a[a.size()-1];
            if(ele>firstmax)
            {
                secondmax = firstmax;
                firstmax = ele;
            }
            else if(ele>secondmax)
                secondmax = ele;
        }

        for(auto a:arrays)
        {
            int ele = firstmax;
            if(ele==a[a.size()-1])
                ele = secondmax;
            res = max(res, ele-a[0]);
        }

        return res;
    }
};