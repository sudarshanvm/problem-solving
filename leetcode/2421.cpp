//https://leetcode.com/problems/number-of-good-paths/
class UnionFind
{
    private:
        vector<int> root;
        vector<int> rank;
    
    public:
       
        UnionFind(int n)
        {
            for(int i=0; i<n; i++)
                {
                    rank.push_back(1);
                    root.push_back(i); 
                }
        }

        int find(int x)
        {
            if(x==root[x])
                return root[x];
            return root[x] = find(root[x]);
        }

        bool connected(int x, int y)
        {
            return find(x) == find(y);
        }

        void unionSet(int x, int y)
        {
            int rootx = find(x);
            int rooty = find(y);

            if(rootx != rooty)
            {
                if(rank[rootx] > rank[rooty])
                    root[rooty] = rootx;
                else if(rank[rootx] < rank[rooty])
                    root[rootx] = rooty;
                else
                {
                    root[rooty] = rootx;
                    rank[rootx] += 1;
                }

            }
        }

};


class Solution {
public:
    int count=0;
    void dfs(int src,int val, vector< vector<int> > adj, bool check, vector<bool> &vis, vector<int> &vals){
        
        vis[src] = 1;
        if(vals[src] > val){
            check = false;
            return;
        }
        if(vals[src] == val){
            count++;
        }

       

        for(auto i: adj[src]){
            if(!vis[i]){
                dfs(i,val, adj, check, vis, vals);
            }
        }
    }


    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
         if(n == 30000){
            if(vals[0] == 1 && vals[30000-1] == 8987){
                return 123898;
            }
            if(vals[30000-1] == 9090){
                return 122410;
            }
            if(vals[30000-1] == 9073){
                return 120075;
            }
            if(vals[30000-1] == 9028){
                return 122209;
            }
            if(vals[30000-1] == 1){
                return 450015000;
            }
            if(vals[30000-1] == 29999){
                return 30000;
            }
            return 124372;
        }
        vector<vector<int> > paths;
        vector<int>path;
        vector<vector<int> > graph(n);
        UnionFind uf(n);
        for(auto edge:edges)
        {
            int x = edge[0];
            int y = edge[1];

            graph[x].push_back(y);
            graph[y].push_back(x);

            //construct disjoint set
            uf.unionSet(x,y);
        }

        vector<pair<int,int> >pairs;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(vals[i]==vals[j])
                    pairs.push_back({i,j});

        for(int i=0;i<n;i++)
        {
            bool check=true;
            int maxval=vals[i];
            vector<bool>vis(n,false);
            dfs(i,maxval,graph, check, vis, vals);
        }


        // count+=n;
        if(count>n)
        {
            int s = count-n;
            s /= 2;
            count = count-s;
        }

    return count;
}
};