// problem: https://leetcode.com/problems/last-stone-weight/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone:stones)
            pq.push(stone);

        while(pq.size()>1)
        {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            pq.push(abs(a-b));
        }

        return pq.top();
        
    }
};
