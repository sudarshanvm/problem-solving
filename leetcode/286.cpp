//problem: https://leetcode.com/problems/walls-and-gates/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue< pair<int,int> > q;
        int m=rooms.size();
        int n=rooms[0].size();

        if(m==0)
            return;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(rooms[i][j]==0)
                    q.emplace(i,j);

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for(int i=0;i<4;i++)
            {
                int nx = x+dirs[i].first;
                int ny = y+dirs[i].second;

                if(nx<0||nx>=m||ny<0||ny>=n||rooms[nx][ny]<rooms[x][y]+1)
                    continue;
                rooms[nx][ny] = rooms[x][y]+1;
                q.emplace(nx,ny);
            }
        }
    }
};
