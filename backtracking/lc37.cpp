//problem: https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
bool isunassigned(vector<vector<char> >temp,int &row,int &col)
    {
        for(int row=0;row<9;row++)
            for(int col=0;col<9;col++)
                if(temp[row][col]=='.')
                    return true;
        return false;
    }
     bool issafe(vector< vector<char> > &temp, int row, int col, char num)
    {
        if(temp[row][col]!='.')
            return false;
         
        //check same col
        for(int j=0;j<9;j++)
            if(temp[row][j]==num)
                return false;
        
        //check same row
        for(int i=0;i<9;i++)
            if(temp[i][col]==num)
                return false;
        
        //check 3x3 sub-matrix
        row= row-row%3; 
        col=col-col%3;
        for(int i=row;i<row+3&&i<9;i++)
            for(int j=col;j<col+3&&j<9;j++)
            if(temp[i][j]==num)
                return false;

        return true;
    }

    bool solve(vector<vector<char>> &board, int row, int col)
    {
        if(row==9) return true;
        if(col==9) return solve(board, row+1, 0);

        if(board[row][col] != '.') return solve(board, row, col+1);

        for(char i='1';i<='9';i++)
        {
            if(issafe(board,row,col,i))
            {
                board[row][col]=i;
                if(solve(board,row,col+1)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
