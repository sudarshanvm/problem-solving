//problem: https://leetcode.com/problems/remove-interval/

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& r) {
        
        vector<vector<int>> res;
        int n=intervals.size();

        int start = r[0], end = r[1];
        for(auto i:intervals)
        {
            int a = i[0];
            int b = i[1];
            
            if(a>end || b<start)
                res.push_back({a,b});
            else
            {
                if(a<start)
                    res.push_back({a,start});
                
                if(b>end)
                    res.push_back({end,b});
            }
        }

        return res;
    }
};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& r) {
        
        vector<vector<int>> res;
        int n=intervals.size();

        int start = r[0], end = r[1];
        for(auto i:intervals)
        {
            int a = i[0];
            int b = i[1];

            //a & b in interval
            if(start < a && b < end)
                continue;

            //only a in interval
            if(start<a && a<end)
            {
                if(end!=b) res.push_back({end, b});
            }
                

            //only b in interval
            else if(start<b && b<end)
            {
                if(a!=start) res.push_back({a,start});
            }
                
            else if(a>=end || start>=b)
                //not overlapping
                res.push_back({a,b});

            else 
            {
                if(a!=start) res.push_back({a, start});
                if(end != b) res.push_back({end,b});
            }
        }

        return res;
    }
};
