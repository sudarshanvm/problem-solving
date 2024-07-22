//problem: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node* node, Node* res, unordered_map<Node*, Node*>& clones) {
        clones[node] = res;
        
        for (auto neigh : node->neighbors) {
            if (clones.find(neigh) == clones.end()) {
                Node* newNode = new Node(neigh->val);
                res->neighbors.push_back(newNode);
                dfs(neigh, newNode, clones);
            } else {
                res->neighbors.push_back(clones[neigh]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> clones;
        Node* res = new Node(node->val);
        dfs(node, res, clones);
        return res;
    }
};
