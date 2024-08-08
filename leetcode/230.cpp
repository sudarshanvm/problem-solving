//problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    vector<int> a;
    void solve(TreeNode* root,int k)
    {
        if(!root)
            return;
        if(a.size()==k)
            return;
        solve(root->left,k);
        a.push_back(root->val);
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
       
        if(!root)
            return -1;
        solve(root,k);
        return a[k-1];

    }
};
