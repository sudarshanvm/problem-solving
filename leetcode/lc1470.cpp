class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int left = 0, right = n;
        vector<int>res;
        while(right<nums.size())
        {
            cout<<"left = "<<left<<" right = "<<right<<endl;
            res.push_back(nums[left++]);
            res.push_back(nums[right++]);
        }
        return res;
    }
};