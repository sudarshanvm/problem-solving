// problem: https://leetcode.com/problems/find-the-town-judge/?envType=problem-list-v2&envId=x1wy4de7
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0);
        vector<bool> vis(n+1,false);

        for(auto t:trust)
        {
            indegree[t[1]]++;
            vis[t[0]]=true;
        }   

        for(int i=1;i<=n;i++)
            if(!vis[i] && indegree[i]==n-1)
                return i;

        return -1;
    }
};
