//problem : https://leetcode.com/problems/lonely-pixel-i/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& p) {
        int row[p.size()];
        int col[p[0].size()];

        //initialize
        for(int i=0;i<p.size();i++)
            row[i]=0;
        for(int j=0;j<p[0].size();j++)
            col[j]=0;

        for(int i=0;i<p.size();i++)
        {
            for(int j=0;j<p[0].size();j++)
            {
                if(p[i][j]=='B')
                {
                        row[i]++;
                        col[j]++;
                }
            }
        }

        int count=0;
        for(int i=0;i<p.size();i++)
        {
            for(int j=0;j<p[0].size();j++)
            {
                if(row[i]==1&&col[j]==1&&p[i][j]=='B')
                    count++;
            }
        }

        return count;
    }
};
