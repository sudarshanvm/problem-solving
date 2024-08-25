// problem: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
class UnionFind {
    vector<int> root;
    vector<int> rank;
    int count=0;
    public:

    UnionFind(int n)
    {
        count=n;
        for(int i=0;i<n;i++)
        {
            root.push_back(i);
            rank.push_back(1);
        }
    }

    void unionSet(int x, int y)
    {
        int rx = find(root[x]);
        int ry = find(root[y]);

        if(rx!=ry)
        {
            if(rank[rx] > rank[ry])
                root[ry] = rx;
            else if(rank[rx] < rank[ry])
                root[rx] = ry;
            else
            {
                root[ry] = rx;
                rank[rx] += 1;
            }
            count--;
        }
    }

    int find(int x)
    {
        if(x==root[x])
            return x;
        return root[x]=find(root[x]);
    }

    int getCount()
    {
        return count;
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);

        for(int i=0;i<n;i++)
        {
            int row = stones[i][0];
            int col = stones[i][1];
            for(int j=i+1;j<n;j++)
            {
                int row1 = stones[j][0];
                int col1 = stones[j][1];

                if( row == row1 || col == col1)
                    uf.unionSet(i,j);
            }
        }

        return n-uf.getCount();
    }
};
