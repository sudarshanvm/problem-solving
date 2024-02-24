//problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto num:nums)
            pq.push(num);
        int num=-1;
        while(k--)
        {
            if(pq.empty())
                return -1;
            num=pq.top();
            pq.pop();
        }
        return num;
    }
};