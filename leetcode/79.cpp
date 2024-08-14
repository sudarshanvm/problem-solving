//problem: https://leetcode.com/problems/word-search/
class Solution {
public:
    bool solve(vector< vector<char>> & board, int row, int col, string& w)
    {
        if(!w.size())
            return true;
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || w[0]!=board[row][col])
            return false;
        char temp = board[row][col];
        board[row][col]='*';
        string word=w.substr(1);
        bool res= solve(board,row-1,col,word) or           solve(board,row+1,col,word) or solve(board,row,col-1,word) or solve(board,row,col+1,word);
        board[row][col]=temp;
        
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int i=0,j=0;
        for(i=0;i<board.size();i++)
        {
            for(j=0;j<board[0].size();j++)
            {
                    if(solve(board,i,j,word))
                        return true;
            }
        }
        // return solve(board,0,0,word,0);
        return false;
    }
};
