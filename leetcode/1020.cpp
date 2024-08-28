// problem: https://leetcode.com/problems/number-of-enclaves/
class Solution {
public:

    void dfs(vector<vector<int>>& grid, int x, int y, int m, int n)
    {
        if(x >= m || x < 0 || y >= n || y < 0)
            return;

        vector<int> rows = {1,-1,0,0};
        vector<int> cols = {0,0,1,-1};

        grid[x][y] = 0;
        for(int i=0;i<4;i++)
        {
            int nx = x + rows[i];
            int ny = y + cols[i];

            if(nx <= m-1 && nx >= 0 && ny <= n-1 && ny >= 0 && grid[nx][ny]==1)
                dfs(grid,nx,ny,m,n);
        }
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        for(int j=0;j<n;j++)
            if(grid[0][j])
                dfs(grid,0,j,m,n);

        for(int j=0;j<n;j++)
            if(grid[m-1][j])
                dfs(grid,m-1,j,m,n);

        for(int i=0;i<m;i++)
            if(grid[i][0])
                dfs(grid,i,0,m,n);

        for(int i=0;i<m;i++)
            if(grid[i][n-1])
                dfs(grid,i,n-1,m,n);

        int count = 0 ;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                    count += 1;

        return count;
    }
};
