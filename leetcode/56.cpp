// https://leetcode.com/problems/merge-intervals/
class Solution {
public:

    bool isOverlap(vector<int> a, vector<int> b)
    {
        if(a[0]<b[1] && b[0]<=a[1]) 
            return true;
        return a[0]==b[0];
    }

    vector<int> mergeIntervals(vector<int> a, vector<int> b)
    {
        return {min(a[0],b[0]),max(a[1],b[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> a=res.back();
            vector<int> b=intervals[i];
            if(isOverlap(a,b))
            {    
                res.pop_back();
                res.push_back(mergeIntervals(a,b));
            }
            else
                res.push_back(b);
        }
        
        return res;
    }
};

// [[1,4],[0,2],[3,5]]

// 0,2   1,4   3,5
