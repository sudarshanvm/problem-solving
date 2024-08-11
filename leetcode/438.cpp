//problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:


    bool check(unordered_map<char,int> window, unordered_map<char,int> count)
    {
        for(auto c:count)
        {    
            if(count[c.first] != window[c.first])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        if(p.size()>s.size())
            return {};
        
        int n = s.size();
        vector<int> res;

        int left=0, right=0;
        unordered_map<char,int> window;
        unordered_map<char,int> count;

        for(auto pchar:p)
            count[pchar] += 1;

        while(right<p.size() && right<n)
            window[s[right++]] += 1;

        if(check(window,count))
            res.push_back(left);

        while(right<n)
        {
            window[s[left++]] -= 1;
            window[s[right++]] += 1;

            if(check(window,count))
                res.push_back(left);
        }

        return res;
        
    }
};
