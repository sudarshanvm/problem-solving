// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:

    int countDays(vector<int> weights,int cap)
    {
        int count=1;
        long long sum=0;
        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i]<=cap)
            {
                sum += weights[i];
            }
            else
            {    
                count++;
                sum=weights[i];
            }
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        long long low=*max_element(weights.begin(),weights.end()), high=1e9;

        while(low<high)
        {
            long long mid = low + (high-low)/2;
            long long num_days = countDays(weights,mid);
            if(num_days>days)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
