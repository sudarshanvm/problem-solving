// problem: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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

    void solve(Node* root, vector<int> & res)
    {
        if(!root)
            return;

        for(auto child: root->children)
            solve(child,res);
        res.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        if(!root)
            return vector<int> ();

        vector<int> res;
        solve(root,res);
        return res;
    }
};
