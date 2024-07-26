//problem: https://leetcode.com/problems/find-the-safest-path-in-a-grid/
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValidCell(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    void bfs(int n, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> multiSourceQueue;

        // Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                // Check neighboring cells
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    // Check if the neighboring cell is valid and unvisited
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }
    }



    int solve(vector<vector<int> >& grid)
    {
        int m=grid.size(), n=grid[0].size();
        int res=0;

        if(m==0)
            return 0;

        vector<vector<int>> vis(m,vector<int> (n,0));
        
        priority_queue<vector<int>> pq;

        pq.push(vector<int>{grid[0][0], 0, 0}); 
        grid[0][0] = -1; 

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if (curr[1] == n - 1 && curr[2] == n - 1) {
                return curr[0];
            }

            for (auto& d : dir) {
                int di = d[0] + curr[1];
                int dj = d[1] + curr[2];
                if (isValidCell(grid, di, dj) && grid[di][dj] != -1) {
                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
                    grid[di][dj] = -1;
                }
            }
        }

        return -1;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        bfs(n,grid);
        int res = solve(grid);
        return res;
    }
};
