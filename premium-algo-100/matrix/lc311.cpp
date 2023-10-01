//problem : https://leetcode.com/problems/sparse-matrix-multiplication/

class Solution {
public:

    int calcRes(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int row, int col)
    {
        int k = mat1[row].size();
        int res=0;
        for(int i=0;i<k;i++)
            res += (mat1[row][i]*mat2[i][col]);
        return res;
    }

    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m=mat1.size();
        int n= mat2[0].size();
        vector<vector<int>> res (m, vector<int> (n));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[i][j]=calcRes(mat1,mat2,i,j);
            }

        }
        return res;
    }
};
