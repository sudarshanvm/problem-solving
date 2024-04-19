class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>m;
        for(auto num:nums1)
            m[num]=true;

        for(auto num:nums2)
            if(m[num])
                return num;

        return -1;
    }
};