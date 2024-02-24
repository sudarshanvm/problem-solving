
//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    
    void solve(TreeNode* root, int &res, int level)
    {
        if(!root)
            return;
        solve(root->left,res,level+1);
        res=max(res,level);
        solve(root->right,res,level+1);
    }
    
    int maxDepth(TreeNode* root) {
        int res=0, level=1;
        solve(root,res,level);
        return res;
    }
};