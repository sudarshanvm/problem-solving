//problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* res = NULL;
    bool solve(TreeNode* root, int p, int q) {
        if (!root)
            return false;

        bool mid = (root->val == p || root->val == q);

        bool left = solve(root->left, p, q);
        bool right = solve(root->right, p, q);

        if ((mid && left) || (mid && right) || (left && right)) {
            res = root;
        }

        return mid || left || right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)
            return nullptr;

        solve(root,p->val,q->val);
        return res;
        
    }
};
