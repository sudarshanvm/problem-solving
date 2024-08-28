// problem: https://leetcode.com/problems/find-center-of-star-graph/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;

        for(auto edge:edges)
        {
            int x = edge[0];
            int y = edge[1];
            m[x]++;
            m[y]++;
        }

        int res=0;
        for(auto item:m)
        {
            if(item.second==edges.size())
                return item.first;
        }

        return -1;
    }
};
