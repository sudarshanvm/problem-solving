// problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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

    void parse(TreeNode* root, vector<int> &res)
    {
        if(!root)
            return;
        parse(root->left,res);
        res.push_back(root->val);
        parse(root->right,res);
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        if(!root->left && !root->right)
            return false;
        vector<int> res;
        parse(root,res);

        int left=0, right=res.size()-1;
        while(left<right)
        {
            int sum = res[left]+res[right];
            if(sum>k)
                right--;
            else if(sum<k)
            {
                left++;
            }
            else
                return true;
        }

        return false;
    }
};
