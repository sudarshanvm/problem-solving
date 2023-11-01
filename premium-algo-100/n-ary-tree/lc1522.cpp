//problem: https://leetcode.com/problems/diameter-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    int solve(Node* root, int& res)
    {
        if(!root)
            return 0;

        int mx = 0, path;
        for(auto child: root->children)
        {

            path = solve(child, res);
            res = max(path+mx, res);
            mx = max(mx, path);
        }
        return 1+mx;
    }

    int diameter(Node* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};
