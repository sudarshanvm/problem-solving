//problem : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

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
    void solve(TreeNode* root, int count, int &res)
    {
        if(!root)
            return;

        if(!root->left&&!root->right)
        {
            res = max(res, count);
            return;
        }

        if(root->left)
        {
            if(root->left->val-root->val==1)
                solve(root->left,count+1, res);
            else
                solve(root->left,0,res);
        }

        if(root->right)
        {
            if(root->right->val-root->val==1)
                 solve(root->right, count+1, res);
            else
                solve(root->right, 0, res);
        }
           

        res = max(res, count);
        return;
    }

    int longestConsecutive(TreeNode* root) {
        int res = 0;
        solve(root,0, res);
        return res+1;
    }
};
