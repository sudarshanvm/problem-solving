//problem: https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    
    bool issafe(int row, int col, vector<vector<int>> temp)
    {
        //check row till cur col
        int n= temp.size();
        for(int j=0;j<col;j++)
            if(temp[row][j])
                return false;
        
        //check same col upper rows
        for(int i=0;i<row;i++)
            if(temp[i][col])
                return false;
        
        //check left top diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(temp[i][j])
                return false;
        
            //check right top diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++)
            if(temp[i][j])
                return false;

        return true;
    }
    
    void solve(int n, int row, int &count, vector<vector<int>> a)
    {
        if(row==n)
        {
            count++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(issafe(row,i,a))
            {
                a[row][i]=1;
                solve(n,row+1,count,a);
                a[row][i]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i = 0; i < n; i++) 
        { 
            for(int j = 0; j < n; j++) 
            { 
                a[i][j] = 0; 
            } 
        } 
        solve(n,0,count,a);
        return count;
    }
};
