//problem: https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    
    void solve(TreeNode* root,  vector<vector<int>> &m, int level)
    {
        if(!root)
        {
            return;
        }
        if(level==m.size())
            m.push_back(vector<int>());
        m[level].push_back(root->val);
        solve(root->left, m, level+1);
        
        solve(root->right,m,level+1);
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int, vector<int>> m;
        vector<vector<int>> res;
        int level=0;
        solve(root,res,level);
       
        return res;
    }
};