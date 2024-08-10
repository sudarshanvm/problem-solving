//problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0, high=numbers.size()-1;
        while(low<high)
        {
            int sum = numbers[low]+numbers[high];
            if(sum==target)
                return {low+1,high+1};

            if(sum<target)
                low++;
            else
                high--;
        }

        return {-1,-1};
    }
};
