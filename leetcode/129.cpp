//problem: https://leetcode.com/problems/sum-root-to-leaf-numbers/
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

    void solve(TreeNode* root, vector<int> path, vector< vector<int> > &allPaths)
    {
        if(!root)
            return;

        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            allPaths.push_back(path);
            return;
        }

        solve(root->left, path, allPaths);
        solve(root->right, path, allPaths);
    }

    int getNumber(vector<int> path)
    {
        int num=0;
        for(auto p:path)
            num = num*10 + p;
            
        return num;
    }

    int sumNumbers(TreeNode* root) {
        vector< vector<int> > allPaths;
        vector<int> path;

        solve(root, path, allPaths);

        int res=0;
        for(auto p: allPaths)
        {
            int number = getNumber(p);
            res += number;
        }

        return res;
        
    }
};
