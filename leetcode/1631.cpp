//problem: https://leetcode.com/problems/path-with-minimum-effort/

typedef pair<int,int> pi;
typedef pair<int,pi > pii;
class Solution {
public:

    int bfs(vector<vector<int>>& heights)
    {
        int n=heights.size(), m=heights[0].size();
        int res  = INT_MIN;
        priority_queue< pii, vector<pii>, greater<pii> > pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pi temp = {0,0};
        pq.push({0,temp});

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty())
        {
             pair<int,pair<int,int>> it=pq.top();
             int effort=it.first;
             int row=it.second.first;
             int col=it.second.second;
             pq.pop();

            if(row==n-1 && col==m-1)
            return effort;

             for(int i=0;i<4;i++)
             {
                 int nrow=row+delrow[i];
                 int ncol=col+delcol[i];

                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                 {
                     int diff=abs(heights[row][col]-heights[nrow][ncol]);
                     int maxi=max(diff,effort);
                     if(maxi<dist[nrow][ncol])
                     {
                         dist[nrow][ncol]=maxi;
                          pq.push({maxi,{nrow,ncol}});
                     }
                 }
             }
        }

        return 0;
        
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();

        if(m==0||n==0)
            return 0;

        int res = bfs(heights);

        return res;
    }
};

