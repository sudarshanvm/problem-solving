// problem: https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-08-27
typedef pair<int,int> pi;
typedef pair<int,double> pd;
using namespace std;

typedef pair<int, double> pd; // Pair of (node, probability)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create the adjacency list for the graph
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob); // The graph is undirected
        }

        // Priority queue (max-heap) to store (probability, node)
        queue<pd> q;
        q.push({start_node, 1}); // Start with the starting node with probability 1.0

        // Vector to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        while (!q.empty()) {
            auto it = q.front();
            double prob = it.second;
            q.pop();

            // Explore neighbors
            for(auto v:graph[it.first])
            {
                int x = v.first;
                double temp = v.second;
                temp = temp * prob;
                if(temp > maxProb[x])
                {
                    maxProb[x]=temp;
                    q.push({x,temp});
                }
            }
        }

        return maxProb[end_node]; 
    }
};

