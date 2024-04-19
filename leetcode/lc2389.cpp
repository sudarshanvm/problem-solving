class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        for(auto q:queries)
        {
            int left=0,sum=0,i=0;
            for(i=0;i<nums.size();i++)
            {
                sum += nums[i];
                if(sum>q)
                {
                    break;
                }
            }

            res.push_back(i);
        }
        return res;
    }
};