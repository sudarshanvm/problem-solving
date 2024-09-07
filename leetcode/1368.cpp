// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/?envType=problem-list-v2&envId=shortest-path
typedef long long ll;
class Solution {
public:
    vector<int> rows = {1, -1, 0, 0};
    vector<int> cols = {0, 0, 1, -1};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<ll> > dp(m,vector<ll> (n,LLONG_MAX)); //dp[i][j] : min cost to reach i,j

        queue<pair<int,int> > q;
        q.emplace(0,0);
        dp[0][0]=0;
        unordered_map<int,pair<int,int> > arrowDirs;
        arrowDirs[1]={0,1}; arrowDirs[2]={0,-1}; arrowDirs[3]={1,0}; arrowDirs[4]={-1,0};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+rows[i];
                int ny=y+cols[i];

                if(nx<0 || nx>=m || ny<0 || ny>=n)  
                    continue;

                ll cost = (arrowDirs[grid[x][y]] == make_pair(rows[i], cols[i])) ? 0 : 1;

                if (dp[x][y] + cost < dp[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + cost;
                    q.emplace(nx, ny);
                }
                
                if(cost + dp[x][y] < dp[nx][ny])
                {
                    dp[nx][ny]=cost+dp[x][y];
                    q.emplace(nx,ny);
                }
            }
        }

        return dp[m-1][n-1];
    }
};

