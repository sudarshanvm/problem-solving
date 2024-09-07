
// topological sort using kahn's algorithm
// Ref: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
vector<int> topologicalSort(vector<vector<int> >& adj,
                            int V)
{
    vector<int> indegree(V, 0); 
        for (const auto& pair : edges) {
            adj[pair[0]].push_back(pair[1]);
            inDegree[pair[1]]++;
        }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : adj[node]) {
            indegree[it]--;

            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // Check for cycle
    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }

    return result;
}