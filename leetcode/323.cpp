//problem : https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
class UnionFind {
    vector<int> rank;
    vector<int> root;
    int count = 0;

    public:
        UnionFind(int n)
        {
            for(int i=0;i<n;i++)
            {
                root.push_back(i);
                rank.push_back(1);
            }
            count = n;
        }

        int find(int x)
        {
            if(x == root[x])
                return x;

            return root[x] = find(root[x]);
        }

        void unionSet(int x, int y)
        {
            int rx = find(x);
            int ry = find(y);

            if(rx != ry)
            {
                if(rank[rx] > rank[ry])
                    root[ry] = rx;
                else if(rank[ry] > rank[rx])
                    root[rx] = ry;
                else
                {
                    rank[rx] += 1;
                    root[ry] = rx;
                }
                count--;
            }
        }

        int getCount()
        {
            return count;
        }


};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for(auto edge: edges)
        {
            int x = edge[0], y = edge[1];
            uf.unionSet(x,y);
        }

        return uf.getCount();
    }
};
