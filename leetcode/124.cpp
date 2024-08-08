//problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

    int solve(TreeNode* root, int &res)
    {
        if(!root)
            return 0;

        int leftsum = max(solve(root->left, res),0);
        int rightsum = max(solve(root->right, res),0);
        // int curgain = max(leftsum,right)+root->val;

        res = max(res, leftsum+rightsum+root->val);

        return max(leftsum+root->val, rightsum+root->val);
    }

    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int temp = solve(root, res);
        return max(temp,res);
    }
};
