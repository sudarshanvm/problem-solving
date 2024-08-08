//problem: https://leetcode.com/problems/validate-binary-search-tree/
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
    vector<int>bst;
    void isValidBSTHelper(TreeNode* root)
    {
        if(!root)
            return ;
        isValidBSTHelper(root->left);
        bst.push_back(root->val);
        isValidBSTHelper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;

        isValidBSTHelper(root);
        for(int i=1;i<bst.size();i++)
        {
            if(bst[i-1]>=bst[i])
                return false;
        }
        return true;
        
    }
};
