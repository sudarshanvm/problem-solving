// problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
/*
1. union find to generate the disjoint sets
2. keep count of number of edges leading to a cycle - cycle_edges
3. if cycle_edges < number of sets-1, then return -1
4. return number of sets - 1
*/

class UnionFind {
    vector<int> root;
    vector<int> rank;
    int count=0;

    public:

        UnionFind(int n)
        {
            count = n;
            for(int i=0;i<n;i++)
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
                return false;

            if(rank[rx] > rank[ry])
                root[ry] = rx;
            else if(rank[rx] < rank[ry])
                root[rx] = ry;
            else
            {
                rank[rx] += 1;
                root[ry] = rx;
            }

            count--;
            return true;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int cycle_edges=0;
        for(auto connection: connections)
        {
            int x = connection[0];
            int y = connection[1];

            if(!uf.unionSet(x,y))
                cycle_edges++;
        }

        int num_sets = uf.getCount();
        return cycle_edges< num_sets-1?-1:num_sets-1;
    }
};

