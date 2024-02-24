//problem: https://leetcode.com/problems/number-of-islands/
class UnionFind
{
    private:
        vector<int> root;
        vector<int> rank;
        int count;
    
    public:
        
        UnionFind(vector<vector<char>>& grid) {
            count = 0;
            int m = grid.size();
            int n = grid[0].size();
              for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                  if (grid[i][j] == '1') {
                    root.push_back(i * n + j);
                    ++count;
                  }
                  else root.push_back(-1);
                  rank.push_back(0);
                }
            }
          }
    
        int find(int x)
        {
            if(x==root[x])
                return x;
            return root[x] = find(root[x]);
        }
    
        bool connected(int x, int y)
        {
            return find(x) == find(y);
        }
    
        void Union(int x, int y)
        {
            int rx = find(x);
            int ry = find(y);
            if(rx!=ry)
            {
                root[ry]=rx;
                count--;
            }
        }
            
        int getCount()
        {
            return count;
        }
    
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        int nr=grid.size(), nc=grid[0].size();
        
        for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
          if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
          if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
        }
      }
    }
        
        return uf.getCount();
        
    }
};