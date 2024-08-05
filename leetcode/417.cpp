//problem: https://leetcode.com/problems/pacific-atlantic-water-flow/
typedef pair<int,int> pi;
class Solution {
public:

    bool safe(vector<vector<int> > &heights, vector<vector<bool> >& vis, int i, int j)
    {
        if(i<0||j<0||i>heights.size()-1||j>heights[0].size()-1||vis[i][j])
            return false;
        return true;
    }

    void dfs(vector<vector<int> > &heights, vector<vector<bool> >& vis, int i, int j)
    {
        int m=heights.size();
        int n=heights[0].size();
        vis[i][j]=true;

        vector<int> rows = {0,0,1,-1};
        vector<int> cols = {1,-1,0,0};

        for(int x=0;x<4;x++)
        {
            int nx = i+rows[x];
            int ny = j+cols[x];
            if(safe(heights,vis,nx,ny) && heights[nx][ny]>=heights[i][j])
                dfs(heights,vis,nx,ny);
        }
        
        return;
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool> > p(m, vector<bool> (n,false));
        vector<vector<bool> > a(m, vector<bool> (n,false));

        for(int i=0;i<m;i++)
            dfs(heights,p,i,0);

        for(int i=0;i<n;i++)
            dfs(heights,p,0,i);

        for(int i=0;i<m;i++)
            dfs(heights,a,i,n-1);

        for(int i=0;i<n;i++)
            dfs(heights,a,m-1,i);

            
        vector<vector<int> > res;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {

                cout<<p[i][j]<<"-"<<a[i][j]<<" ";
                if(a[i][j] && p[i][j])
                {
                    vector<int>temp={i,j};
                    res.push_back(temp);
                }
            }
            cout<<endl;
        }

        return res;
    }
};
