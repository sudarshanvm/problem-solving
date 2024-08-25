// problem: https://leetcode.com/problems/satisfiability-of-equality-equations/

class UnionFind {
    vector<int> root;
    vector<int> rank;

    public:

        UnionFind(int n)
        {
            for(int i=0;i<n;i++)
            {
                root.push_back(i);
                rank.push_back(1);
            }
        }

        void unionSet(int x , int y)
        {
            int rx = find(root[x]);
            int ry = find(root[y]);

            if(rx != ry)
            {
                if(rank[rx] > rank[ry])
                    root[ry]=rx;
                else if(rank[rx]<rank[ry])
                    root[rx]=ry;
                else
                {
                    rank[rx]++;
                    root[ry]=rx;
                }
            }
        }

        int find(int x)
        {
            if(x==root[x])
                return x;

            return root[x]=find(root[x]);
        }

        bool connected(int x, int y)
        {
            return find(x) == find(y);
        }

};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = 26;
        UnionFind uf(n);

        vector<string> check;
        for(auto eq: equations)
        {
            char x = eq[0];
            char y = eq[3];

            if(eq[1] == '=')
                uf.unionSet(x-'a',y-'a');
            else
                check.push_back(eq);
        }

        for(auto eq: check)
        {
            char x = eq[0];
            char y = eq[3];
            if(uf.connected(x-'a',y-'a'))
                    return false;
        }

        return true;
    }
};


/*
1. union find
2. if ==, then union a and b
3. if !=, then check if a and b connected, if connected then return false
4. return true
*/
