//problem : https://leetcode.com/problems/find-leaves-of-binary-tree/

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
    TreeNode* solve(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return NULL;

        if(!root->left&&!root->right) //leaf node
        {
            v.push_back(root->val);
            cout<<"-"<<root->val<<"-";
            return NULL;
        }

        root->left = solve(root->left, v);
        root->right = solve(root->right, v);
        return root;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;

        while(root)
        {
            vector<int>v;
            root=solve(root, v);
            res.push_back(v);
        }
        

        return res;
    }
};
