//problem: https://leetcode.com/problems/swim-in-rising-water/

typedef pair<int,int> ipair;
typedef pair<int,ipair> iipair;

class Solution {
public:

    bool issafe(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||vis[x][y])
            return false;
        return true;
    }


    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int res=0;

        if(m==0)
            return 0;

        vector<vector<int>> vis(m,vector<int> (n,0));
        
        priority_queue< iipair , vector<iipair>, greater<iipair> > pq;
        pq.push(make_pair(grid[0][0],make_pair(0,0)));
        vis[0][0] = true;

        while(!pq.empty())
        {
            iipair iip = pq.top(); pq.pop();
            res = iip.first;
            int row = iip.second.first, col=iip.second.second;

            if(row==m-1 && col==n-1)
                return res;

            if(row>=m||col>=n)
                return res;

            if(issafe(row,col+1,grid,vis))
            {
                pq.push(make_pair(max(res,grid[row][col+1]),make_pair(row,col+1)));
                vis[row][col+1]=true;
            }
            if(issafe(row,col-1,grid,vis))
            {
                vis[row][col-1]=true;
                pq.push(make_pair(max(res,grid[row][col-1]),make_pair(row,col-1)));
            }
                
            if(issafe(row+1,col,grid,vis))
            {
                vis[row+1][col]=true;
                pq.push(make_pair(max(res,grid[row+1][col]),make_pair(row+1,col)));
            }
                
            if(issafe(row-1,col,grid,vis))
            {
                vis[row-1][col]=true;
                pq.push(make_pair(max(res,grid[row-1][col]),make_pair(row-1,col)));
            }
                

        }

        return res;
    }
};
