// https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=problem-list-v2&envId=shortest-path
typedef pair<int,int> pi;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pi>> adj(n+1);
        for(auto flight:flights)
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        queue<pair<int,pi> > q;
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        q.push({src,{0,0}});
        while(!q.empty())
        {
            int y=q.front().first;
            int l=q.front().second.first;
            int d=q.front().second.second;
            q.pop();

            for(auto flight:adj[y])
            {
                if(d+flight.second<dist[flight.first] && k>=l)
                {
                    dist[flight.first]=d+flight.second;
                    q.push({flight.first,{l+1,dist[flight.first]}});
                }
            }
        }

        if(dist[dst]>=INT_MAX)
            return -1;
        return dist[dst];
    }
};
