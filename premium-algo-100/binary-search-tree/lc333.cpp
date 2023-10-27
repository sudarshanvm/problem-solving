//problem: https://leetcode.com/problems/largest-bst-subtree/

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

    bool IsBST(TreeNode* root, int min, int max)
    {
        if(!root) return true;

        if (root->val <= min || root->val >= max) return false;

        int left = IsBST(root->left,min,root->val);
        int right = IsBST(root->right,root->val,max);

        return left && right;
    }

    int size (TreeNode* root)
    {
        if(!root) return 0;

        int left = size(root->left);
        int right = size(root->right);

        return left + right + 1;
    }

    int largestBSTSubtree(TreeNode* root) {
         if(!root)return 0;

        if(IsBST(root,INT_MIN,INT_MAX))
            return size (root);
        
        int left = largestBSTSubtree(root->left);
        int right = largestBSTSubtree(root->right);

        return max(left,right);
    }
};
