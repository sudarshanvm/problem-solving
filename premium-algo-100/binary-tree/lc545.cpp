//problem : https://leetcode.com/problems/boundary-of-binary-tree/

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

    void leavessolve(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;

        if(!root->left&&!root->right)
        {
            v.push_back(root->val);
            return;
        }

        leavessolve(root->left, v);
        leavessolve(root->right, v);
        return;
    }

    void rightsolve(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;

        if(!root->left&&!root->right)
            return;

        if(root->right)
        {
            v.push_back(root->val);
            rightsolve(root->right, v);
        }

        else if(root->left)
        {
            v.push_back(root->val);
            rightsolve(root->left, v);
        }

        return;
    }

    void leftsolve(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;

        if(!root->left&&!root->right)
            return;

        if(root->left)
        {
            v.push_back(root->val);
            leftsolve(root->left, v);
        }

        else if(root->right)
        {
            v.push_back(root->val);
            leftsolve(root->right, v);
        }

        return;
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>res;
        // vector<int>right;
        vector<int>res2;
        if(!root)
            return res;
        res.push_back(root->val);
        leftsolve(root->left, res);
        leavessolve(root->left, res);
        leavessolve(root->right, res);
        rightsolve(root->right, res2);
        
        reverse(res2.begin(), res2.end());
        res.insert(res.end(), res2.begin(), res2.end());

        return res;
    }
};
