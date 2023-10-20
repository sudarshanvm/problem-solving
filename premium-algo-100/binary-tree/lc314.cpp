//problem: https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

class Solution {
public:

    void solve(TreeNode* root, map<int, vector<pair<int,int> > > &m, int col, int h)
    {
        if(!root)
            return;
        
        m[col].push_back({h,root->val});
        solve(root->left,m,col-1,h+1);
        
        solve(root->right,m,col+1,h+1);
        
        return;
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int,int> > > m;
        vector<vector<int>> res;
        solve(root,m,0,0);

        for(auto i:m)
        {
            vector<int> temp;
            vector<pair<int,int> > vp = i.second;
            sort(vp.begin(), vp.end(), compare);
            for(auto p:vp)
                temp.push_back(p.second);
            res.push_back(temp);
        }
        return res;
    }
};
