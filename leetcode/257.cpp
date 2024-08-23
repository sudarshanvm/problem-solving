//problem: https://leetcode.com/problems/binary-tree-paths/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int> path, vector< vector<int> > &allPaths)
    {
        if(!root)
            return;

        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            allPaths.push_back(path);
            return;
        }

        solve(root->left, path, allPaths);
        solve(root->right, path, allPaths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector< vector<int> > allPaths;
        vector<int> path;

        solve(root, path, allPaths);
        vector<string> res;

        for(auto p:allPaths)
        {
            string s = "";
            for(int i=0;i<p.size();i++)
            {
                string ele = to_string(p[i]);
                if(i==p.size()-1)
                    s += ele;
                else
                    s += ele + "->";
            }

            res.push_back(s);
        }

        return res;
    }
};
