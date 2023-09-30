//problem : https://leetcode.com/problems/find-anagram-mappings/

class Solution {
public:

    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int n = nums1.size();
        unordered_map<int,int>index;
        for(int i=0; i<n; i++)
            index[nums2[i]] = i;
        for(int i=0;i<n;i++)
            res.push_back(index[nums1[i]]);
        return res;
    }
};
