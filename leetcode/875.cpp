// https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:

    int eat(vector<int> piles, int k)
    {
        int h=0;
        for(auto pile:piles)
        {
            int temp = pile/k + 1;
            if(pile%k==0)
                temp--;
            h+=temp;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low=1, high=1e9;
        while(low<high)
        {
            long long mid = low+ (high-low)/2;
            long long hours = eat(piles,mid);
            if(hours>h)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};


