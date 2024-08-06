//problem: https://leetcode.com/problems/path-sum-iii/submissions/1346111647/

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

    long solve(TreeNode* root, long t)
    {
        if(!root)
            return 0;
        
        long res=0;
        if(root->val == t)
            res++;
        
    if(root->left)
        res += solve(root->left,t-root->val);
    if(root->right)
        res += solve(root->right,t-root->val);
        return res; 
    }


    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;

        return solve(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};
