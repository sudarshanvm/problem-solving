//problem: https://leetcode.com/problems/candy-crush/description/

class Solution {
public:
    int n, m;
    bool detect(vector<vector<int>>& board){
        vector<vector<int>> tmp = board;
        bool ret = false;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int k = j;
                while(k<m-1 && tmp[i][k]!=0 && tmp[i][k]==tmp[i][k+1])
                    ++k;
                if(k-j+1 >= 3){
                    ret = true;
                    for(int ii=j; ii<=k; ++ii)
                        board[i][ii]=0;
                }
                k = i;
                while(k<n-1 && tmp[k][j]!=0 && tmp[k][j]==tmp[k+1][j])
                    ++k;
                if(k-i+1 >= 3){
                    ret = true;
                    for(int ii=i; ii<=k; ++ii)
                        board[ii][j]=0;
                }
            }
        }
        return ret;
    }
    void remove(vector<vector<int>>& board){
        for(int i=0; i<m; ++i){
            for(int j=n-1; j>=0; --j){
                int k = j;
                while(k > 0 && board[k][i] == 0){
                    --k;
                }
                swap(board[k][i], board[j][i]);
            }
        }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        while(detect(board))
            remove(board);
        return board;
    }
};
