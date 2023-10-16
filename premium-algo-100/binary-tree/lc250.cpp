//problem : https://leetcode.com/problems/count-univalue-subtrees/

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

    int solve(TreeNode* parent, TreeNode* root, int &count)
    {
        if(!root)
            return 1;

        int isleft = solve(root, root->left, count);
        int isright = solve(root, root->right, count);

        if(isleft && isright)
        {
            count++;
            if(parent == NULL)
                return true;

            return parent->val == root->val;

        }

        return 0;
    }

    int countUnivalSubtrees(TreeNode* root) {
        int count=0;
        solve(NULL, root,count);
        return count;
    }
};
