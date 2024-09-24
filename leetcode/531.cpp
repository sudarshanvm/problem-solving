// https://leetcode.com/problems/minimum-time-difference/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times;
        for(auto time:timePoints)
        {
            int t = stoi(time.substr(0,2))*60 + stoi(time.substr(3));
            times.push_back(t);
        }

        sort(times.begin(),times.end());
        int res=INT_MAX;

        for(int i=1;i<times.size();i++)
        {
            res=min(res,times[i]-times[i-1]);
        }

        res=min(res,abs(times[times.size()-1]-times[0]));
        for(auto time:times)
            cout<<time<<" ";
        res=min(res,1440+times[0]-times[times.size()-1]);
        return res;
    }
};
