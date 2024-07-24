//problem: https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int n) {
        if(n==1)
            return s;

        vector< vector<char> > a(n, vector<char>(1001,'-'));

        int row=0, col=0;
        bool goingDown=true;

        for(int i=0;i<s.size();i++)
        {
            a[row][col] = s[i];
            if (goingDown) {
                if (row == n - 1) {
                    goingDown = false;
                    row--;
                    col++;
                } else {
                    row++;
                }
            } else {
                if (row == 0) {
                    goingDown = true;
                    row++;
                } else {
                    row--;
                    col++;
                }
            }
            
        }

        string res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < col + 1; ++j) {
                // cout<<a[i][j]<<" ";
                if (a[i][j] != '-') {
                    res += a[i][j];
                }
            }
            // cout<<endl;
        }

        return res;
    }
};
