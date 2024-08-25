// problem: https://leetcode.com/problems/redundant-connection/
class UnionFind {
    vector<int> root;
    vector<int> rank;
    public:
    UnionFind(int n)
    {
        root.push_back(0);
        rank.push_back(0);
        for(int i=1;i<=n;i++)
        {
            root.push_back(i);
            rank.push_back(1);
        }
    }

    bool unionSet(int x, int y)
    {
        int rx = find(root[x]);
        int ry = find(root[y]);

        if(rx==ry)
            return false; //cycle

        if(rank[rx] > rank[ry])
            root[ry] = rx;
        else if(rank[rx] < rank[ry])
            root[rx] = ry;
        else
        {
            root[ry] = rx;
            rank[rx] += 1;
        }

        return true;
    }

    int find(int x)
    {
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=0;
        for(auto edge : edges)
        {    
            n = max(n,edge[0]);
            n = max(n,edge[1]);
        }

        
        UnionFind uf(n);

        vector<int> res = {-1,-1};
        for(auto edge:edges)
        {
            if(!uf.unionSet(edge[0],edge[1]))
            {
                res[0] = edge[0];
                res[1] = edge[1];
            }
        }
        return res;
    }
};
