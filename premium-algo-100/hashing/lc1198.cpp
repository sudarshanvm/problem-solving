//problem : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

//optimization2: using binary search

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        
        for(int j=0;j<mat[0].size();j++)
        {
            int ele = mat[0][j];
            bool found = true;
            for(int i=1; i<mat.size();i++)
            {   
                found = binary_search(begin(mat[i]),end(mat[i]),ele);
                if(!found)
                    break;
            }
            if(found)
                return ele;
        }

        return -1;
    }
};

-------------------------------------------------------------------------
//optimization1: 

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int count[10001]={0};
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0; j<mat[0].size();j++)
            {
                int ele = mat[i][j];
                count[ele]++;
            }
        }

        for(int i=0;i<10001;i++)
        {
            if(count[i]==mat.size())
                return i;
        }
        return -1;
    }
};

---------------------------------------------------------------
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
