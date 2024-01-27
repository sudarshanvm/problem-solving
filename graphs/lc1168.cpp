//problem: https://leetcode.com/problems/optimize-water-distribution-in-a-village/

class UnionFind
{
    private:
        vector<int>root;
        vector<int>rank;
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
            return root[x]=find(root[x]);
        }
    
        void unionSet(int x, int y)
        {
            int rx = find(x);
            int ry = find(y);
            
            if(rx!=ry)
            {
                if(rank[rx]>rank[ry])
                    root[ry]=rx;
                else if(rank[rx]<rank[ry])
                    root[rx]=ry;
                else
                {
                    root[ry]=rx;
                    rank[rx]+=1;
                }
            }
        }
    
        bool connected(int x, int y)
        {
            return find(x)==find(y);
        }
    
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector< pair<int, pair<int,int> > > edges;

        for(int i=1;i<=wells.size();i++)
        {
            edges.push_back({wells[i-1],{0,i}});
        }

        UnionFind uf(n+1);
        for(auto pipe: pipes)
        {
            edges.push_back({pipe[2],{pipe[0],pipe[1]}});
        }

        sort(edges.begin(), edges.end());
        int cost = 0;
        for(auto edge: edges)
        {
            if(!uf.connected(edge.second.first,edge.second.second))
            {
                uf.unionSet(edge.second.first, edge.second.second);
                cost += edge.first;
            }
            cout<<edge.second.first<<"-"<<edge.second.second<<endl;
        }

        return cost;
    }
};
