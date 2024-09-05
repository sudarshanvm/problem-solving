// https://leetcode.com/problems/find-missing-observations/
class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=accumulate(rolls.begin(),rolls.end(),0),m=rolls.size();
        int total_sum = mean * (n+m);
        int target = total_sum-sum;
        if(target<n || target>6*n)
            return {};
        vector<int> res(n,1);
        target-=n;

        for(int i=0;i<n;i++)
        {
            if(target<=0)
                break;
            int add = min(target,5);
            res[i]+=add;
            target-=add;
        }
        return res;
    }
};
