
//problem : https://leetcode.com/problems/wiggle-sort/description/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left=1, right=nums.size()-1;
        while(left<=right)
        {
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
            for(int i=0; i<nums.size(); i++)
                cout<<nums[i]<<"-";
            cout<<endl;
        }
    }
};