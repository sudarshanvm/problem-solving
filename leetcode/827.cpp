// https://leetcode.com/problems/making-a-large-island/
typedef pair<int,int> pi;
class Solution {
public:
    int count=0;
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};

    void dfs(vector<vector<int>>& grid, int r, int c, int color)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=1)
            return;
        grid[r][c]=color;
        count++;
        for(int i=0;i<4;i++)
        {
            int x=r+rows[i];
            int y=c+cols[i];
            dfs(grid,x,y,color);
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int color=2;
        unordered_map<int,int> island_size;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                count=0;
                if(grid[i][j])
                {    
                    dfs(grid,i,j,color);
                    island_size[color++]=count;
                }

            }
        }

        if(island_size.find(2)==island_size.end())
            return 1;

        int res=island_size[2],cur_count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cur_count=0;
                set<pi> s; //<color,size>
                if(!grid[i][j])
                {
                    for(int k=0;k<4;k++)
                    {
                        int r=i+rows[k];
                        int c=j+cols[k];
                        if(r>=0 && c>=0 && r<m && c<n && grid[r][c]!=0)
                        {
                            int cur_color=grid[r][c];
                            int cur_size=island_size[cur_color];
                            s.insert({cur_color,cur_size});
                        }
                    }

                    for(auto pair:s)
                        cur_count+=pair.second;
                    res=max(res,cur_count+1);
                }
            }
        }
        return res;
    }
};
