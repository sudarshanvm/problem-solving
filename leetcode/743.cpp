// problem : https://leetcode.com/problems/network-delay-time/
typedef pair<int,int> pi;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < times.size(); ++i) {
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];
            graph[u].emplace_back(v, time);
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, k}); // (time, node)

        // Initialize distances with infinity
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        // Dijkstra's algorithm
        while (!pq.empty()) {
            int currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;
                if (currTime + edgeWeight < minTime[nextNode]) {
                    minTime[nextNode] = currTime + edgeWeight;
                    pq.push({minTime[nextNode], nextNode});
                }
            }
        }

        int res = -1;
        for(int i=1;i<=n;i++)
        {    
            int time = minTime[i];
            if(time==INT_MAX)
                return -1;
            res = max(res,time);
            cout<<time<<"-";
        }

        return res; 
    }
};

