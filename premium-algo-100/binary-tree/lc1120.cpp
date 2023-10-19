//problem : https://leetcode.com/problems/maximum-average-subtree/

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

    double max(double a, double b)
    {
        return a>b?a:b;
    }

    pair<int,double> solve(TreeNode* node, double &res)
    {
        if(!node)
            return {0,0};

        pair<int,double> p1 = solve(node->left, res);
        pair<int,double> p2 = solve(node->right, res);

        int count = 1 + p1.first + p2.first;
        double sum = node->val + p1.second + p2.second;

        res = max(res, count>0?sum/count:0);

        return {count,sum};
        
    }

    double maximumAverageSubtree(TreeNode* root) {
        double res = INT_MIN;
        solve(root, res);
        return res;
    }
};
