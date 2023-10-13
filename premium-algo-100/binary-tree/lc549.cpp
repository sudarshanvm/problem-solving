//problem : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

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
    vector<int> solve(TreeNode* root, int &res)
    {
        if(!root)
            return {0,0};

        int incr=1, decr=1;

        if(root->left)
        {
            vector<int>left = solve(root->left,res);
            if(root->left->val-root->val==-1)
            {
                decr = left[1]+1;
            }
            else if(root->left->val-root->val==1)
                incr = left[0]+1;
        }

        if(root->right)
        {
            vector<int>right = solve(root->right,res);
            if(root->right->val-root->val==-1)
                 decr = max(decr,right[1]+1);
            else if(root->right->val-root->val==1)
                incr = max(incr,right[0]+1);
        }

        res = max(res, incr+decr-1);
        return {incr,decr};
    }

    int longestConsecutive(TreeNode* root) {
        int res = 0;
        solve(root,res);
        return res;
    }
};
