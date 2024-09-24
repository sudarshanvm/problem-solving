// https://leetcode.com/problems/largest-number/
class Solution {
public:
    static bool compare(string a,string b)
    {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for(auto num:nums)
            s.push_back(to_string(num));

        sort(s.begin(),s.end(),compare);
        string res;
        for(auto ch:s)
            res+=ch;
        while(res[0]=='0' && res.size()>1)
        {
            res.erase(0,1);
        }
        return res;
    }
};
