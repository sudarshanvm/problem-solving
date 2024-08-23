//problem: https://leetcode.com/problems/surrounded-regions/
class Solution {
public:

    void dfs(vector<vector<char>>& board, int m, int n, int r, int c, vector< vector<bool> > &vis)
    {
        if(r < 0 || c<0 || r>=m || c>=n || board[r][c]=='X' || vis[r][c])
            return;

        vis[r][c] = true;

        vector<int> rows = {1,-1,0,0};
        vector<int> cols = {0,0,1,-1};

        for(int i=0;i<4;i++)
        {
            int x = r+rows[i];
            int y = c+cols[i];

            dfs(board,m,n,x,y,vis);
        }
    }

    void solve(vector<vector<char>>& board) {

        int m=board.size(), n=board[0].size();
        vector< vector<bool> > vis(m,vector<bool> (n,false));

        if(m==0 || n==0)
            return;

        for(int i=0;i<m;i++)
        {    
            dfs(board,m,n,i,0,vis);
            dfs(board,m,n,i,n-1,vis);
        }

        for(int j=0;j<n;j++)
        {    
            dfs(board,m,n,0,j,vis);
            dfs(board,m,n,m-1,j,vis);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }

        return;
        
    }
};
