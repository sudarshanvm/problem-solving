//problem: https://leetcode.com/problems/top-k-frequent-elements/

typedef pair<int,int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pi> pq;

        unordered_map<int,int> vis;
        unordered_map<int,int> count;

        for(auto num:nums)
            count[num] += 1;

        for(auto num:nums)
        {
            if(vis.find(num)==vis.end())
            {    
                pq.push({count[num],num});
                vis[num] = 1;
            }
        }


        vector<int> res;
        while(!pq.empty() && k--)
        {
            pi temp = pq.top();
            pq.pop();
            res.push_back(temp.second);
        }

        return res;

    }
};
