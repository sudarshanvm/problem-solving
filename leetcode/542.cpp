// problem: https://leetcode.com/problems/01-matrix/
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int> > res (m,vector<int>(n,0));
        vector<vector<bool> > vis(m,vector<bool>(n,false));


        queue< pii > q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    pi temp = {i,j};
                    q.push({temp,0});
                    vis[i][j]=true;
                }
            }

        

        vector<int> rows = {1,-1,0,0};
        vector<int> cols = {0,0,1,-1};

        while(!q.empty())
        {
            pii top = q.front(); q.pop();
            int x = top.first.first; 
            int y = top.first.second;
            int d = top.second;
            
            res[x][y] = d;

            for(int i=0;i<4;i++)
            {
                int nx = x + rows[i];
                int ny = y + cols[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny])
                {
                    pii temp;
                    pi coord = {nx,ny};
                    int dist = mat[nx][ny] == 0? 0:d+1;
                    temp = {coord,dist};
                    q.push(temp);
                    vis[nx][ny] = true;
                }
            }
            
        }

        return res;
        
    }
};
