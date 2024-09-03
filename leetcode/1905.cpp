// problem: https://leetcode.com/problems/count-sub-islands/?envType=daily-question&envId=2024-08-28
class Solution {
public:

    vector<vector<int> > a;
    vector<vector<int> > b;
    bool island = false;
    int m=0,n=0;

    void dfs(int x, int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return ;

        if(a[x][y]==0)
             island = false;

        a[x][y]=0;
        b[x][y]=0;
        if(x>0 && b[x-1][y]) dfs(x-1,y);
        if(y>0 && b[x][y-1]) dfs(x,y-1);
        if(x<m-1 && b[x+1][y]) dfs(x+1,y);
        if(y<n-1 && b[x][y+1]) dfs(x,y+1);

        return ;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();
        a=grid1; b=grid2;

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid2[i][j]<<" ";
                if(grid2[i][j]==1)
                {
                    island=true;
                    dfs(i,j);
                    if(island) count++;
                }
            }

            cout<<endl;
            
        }

        return count;
        
    }
};
