//problem : https://leetcode.com/problems/closest-binary-search-tree-value-ii/?envType=study-plan-v2&envId=premium-algo-100

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

    void parsetree(TreeNode* root, vector<int>& a)
    {
        if(!root)
            return;

        a.push_back(root->val);
        parsetree(root->left, a);
        parsetree(root->right, a);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>a;
        vector<int>res;
        parsetree(root, a); 
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>> >pq;
        for(int i=0;i<a.size();i++)
            pq.push({abs(target-a[i]),i});

        int count=0;
        while(!pq.empty()&&count<k)
        {
            res.push_back(a[pq.top().second]);
            cout<<a[pq.top().second]<<"-"<<target<<"="<<pq.top().first<<" Index: "<<pq.top().second<<endl;
            pq.pop();
            count++;
        }

        return res;

    }
};
