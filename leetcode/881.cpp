// problem: https://leetcode.com/problems/boats-to-save-people/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int left=0, right=people.size()-1,sum=0,boats=0;
        while(left<right)
        {
            sum = people[left]+people[right];
            if(sum<=limit)
            {
                right--;
                left++;
                boats++;
            }
            else
                right--;
        }

        boats = people.size()-boats;

        return boats;
        
    }
};
