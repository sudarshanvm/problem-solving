//problem: https://leetcode.com/problems/min-cost-to-connect-all-points/

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<pair<int, pair<int,int> >> edges;
        UnionFind uf(points.size());
        int res_cost = 0, edges_count=0;

        for(int i=0;i<points.size()-1;i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int cost = abs(x2-x1) + abs(y2-y1);
                edges.push_back({cost,{i,j}});
            }
        }
        
        sort(edges.begin(), edges.end());

        for(auto edge: edges)
        {
            if(!uf.connected(edge.second.first,edge.second.second))
            {
                uf.unionSet(edge.second.first,edge.second.second);
                res_cost += edge.first;
                edges_count++; //to check no. of edges = n-1 in the end, not really needed here
            }
        }

        return res_cost;
    }
};
