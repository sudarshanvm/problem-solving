//problem: https://leetcode.com/problems/accounts-merge/
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

        int find(int x)
        {
            if(x==root[x])
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
                else if(rank[rx] < rank[ry])
                    root[rx] = ry;
                else
                {
                    root[ry] = rx;
                    rank[rx] += 1;
                }
            }
        }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(accounts.size());

        unordered_map<string,int> m;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(m.find(accounts[i][j]) == m.end())
                    m[accounts[i][j]] = i;
                else
                    uf.unionSet(m[accounts[i][j]], i);
            }
        }

        unordered_map<int, vector<string>> mres;
        for (int i = 0; i < accounts.size(); i++) {
            int root = uf.find(i);
            if (mres.find(root) == mres.end()) {
                mres[root] = accounts[i];
            } else {
                mres[root].insert(mres[root].end(), accounts[i].begin() + 1, accounts[i].end());
            }
        }

        vector<vector<string>> res;
        for (auto& item : mres) {
            sort(item.second.begin() + 1, item.second.end());
            auto it = unique(item.second.begin() + 1, item.second.end()); //moves duplicates to end and returns index where duplicates start
            item.second.erase(it, item.second.end());
            res.push_back(item.second);
        }

        return res;

    }
};
