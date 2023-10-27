//problem : https://leetcode.com/problems/closest-binary-search-tree-value/?envType=study-plan-v2&envId=premium-algo-100

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
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        auto child = target < a ? root->left : root->right;
        if(!child)
            return a;
        int b = closestValue(child, target);
        auto diff1 = abs(a-target);
        auto diff2 = abs(b-target);
        if(diff1==diff2)
            return a<b?a:b;
        return diff1<diff2?a:b;
    }
};
