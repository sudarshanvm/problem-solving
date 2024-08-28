// problem: https://leetcode.com/problems/maximum-ice-cream-bars/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto cost:costs)
            pq.push(cost);

        int count=0;
        while(coins>=0)
        {
            int top = pq.top(); pq.pop();
            if(top<=coins)
                count += 1;
            coins -= top;
            
        }

        return min((int) costs.size(),count);
    }
};

