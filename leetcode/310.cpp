// problem: https://leetcode.com/problems/minimum-height-trees/?envType=problem-list-v2&envId=topological-sort
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<int> indegree(n,0);
        vector <vector <int>> g(n);
        for(auto edge:edges)
        {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==1)
                q.push(i);

        while(n>2)
        {
            int qsize = q.size();
            n -= qsize;
            while(qsize--)
            {
                int front = q.front(); q.pop();
                for(int nei: g[front])
                {
                    indegree[nei]-=1;
                    if(indegree[nei]==1)
                        q.push(nei);
                }
            }
        }

        vector<int> res;
        while(!q.empty())
        {
            int front = q.front(); q.pop();
            res.push_back(front);
        }

        return res;
    }
};
