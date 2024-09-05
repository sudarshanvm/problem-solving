// https://leetcode.com/problems/bitwise-ors-of-subarrays/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        if(arr.size()==0)
            return 0;

        unordered_set<int> s,cur_set;
        for(int i=0;i<arr.size();i++)
        {
            unordered_set<int> new_set = {arr[i]};
            for(auto prev: cur_set)
            {    
                new_set.insert(arr[i]|prev);
            }
            cur_set=new_set;
            s.insert(cur_set.begin(),cur_set.end());
        }
        return s.size();
    }
};
