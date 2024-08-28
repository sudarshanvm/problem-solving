// problem: https://leetcode.com/problems/rotting-oranges/
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        queue< pii > q;
        int d=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==2)
                {
                    pi temp = {i,j};
                    q.push({temp,d});
                }

        vector<int> rows = {1,-1,0,0};
        vector<int> cols = {0,0,1,-1};
        
        while(!q.empty())
        {
            pii top = q.front(); q.pop();
            int x = top.first.first;
            int y = top.first.second;
            d = top.second;
            for(int i=0;i<4;i++)
            {
                int nx = x + rows[i];
                int ny = y + cols[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                {
                    pi temp = {nx,ny};
                    q.push({temp,d+1});
                    grid[nx][ny]=2;
                }
            }

        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)  return -1;
                
        return d;
    }
};
