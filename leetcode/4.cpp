// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int n = nums1.size()+nums2.size();

        int k= n%2==0?n/2:(n/2)+1;
        for(int i=0;i<nums1.size();i++)
            pq.push(nums1[i]);
        for(int j=0;j<nums2.size();j++)
            pq.push(nums2[j]);

        double res;
        for(int i=0;i<k-1;i++)
            pq.pop();
        if(n%2==0)
        {    
            int top=pq.top(); pq.pop();
            int top2=pq.top();
            res=(double)(top+top2)/2;
        }
        else
            res=pq.top();
        return res;
    }
};

