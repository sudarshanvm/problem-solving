//problem : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int>m[mat.size()];
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0; j<mat[0].size();j++)
            {
                int ele = mat[i][j];
                m[i][ele] = 1;
            }
        }

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++) 
            {
                bool flag=true;
                int ele = mat[i][j];
                for(int k=0;k<mat.size();k++)
                    if(m[k].count(ele))
                        continue;
                    else
                        flag=false;
                if(flag)
                    return ele;
            }
        }
        return -1;
    }
};
