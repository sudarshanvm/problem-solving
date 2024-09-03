// problem: https://leetcode.com/problems/convert-1d-array-into-2d-array/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m,vector<int> (n,0));
        if(original.size()!=m*n)
            return vector<vector<int>>();
        int count=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                res[i][j] = original[count++];

        
        return res;
    }
};
