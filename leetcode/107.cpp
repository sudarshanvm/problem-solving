//problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int> > res;
    void solve(TreeNode* root, int level)
    {
        if(!root)
            return;

        if(level==res.size())
            res.push_back(vector<int>());
            
        res[level].push_back(root->val);
        solve(root->left, level+1);
        solve(root->right, level+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return vector<vector<int>> ();

        int level = 0;
        solve(root,level);

        int low=0, high=res.size()-1;
        while(low<high)
        {
            swap(res[low],res[high]);
            low++;
            high--;
        }
        return res;
    }
};
