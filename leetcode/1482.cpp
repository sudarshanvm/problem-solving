// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
public:

    int count(vector<int>& bloomDay, int k, int day) {
        int b = 0; // Number of bouquets
        int temp = 0; // Consecutive blooming flowers

        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= day) {
                temp++;
                // If we have enough flowers to form a bouquet
                if (temp == k) {
                    b++;
                    temp = 0; // Reset for the next bouquet
                }
            } else {
                temp = 0; // Reset if the flower is not blooming
            }
        }

        return b;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low=1,high=1e9;
        if((long long)k*m>bloomDay.size())
            return -1;
        while(low<high)
        {
            long long mid = low + (high-low)/2;
            long long num_b = count(bloomDay,k,mid);
            if(num_b < m)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
