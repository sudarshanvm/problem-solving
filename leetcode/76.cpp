//problem: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size()==0)
            return "";

        unordered_map<char,int> smap, tmap;

        for(auto tchar : t)
            tmap[tchar] += 1;

        int left = 0, right = 0, have = 0, need = 0;
        int first = -1,last = -1,res = INT_MAX;

        need = tmap.size();
        while(right<s.size())
        {
            char cur = s[right];
            smap[cur] += 1;

            if(smap[cur] == tmap[cur])
                have += 1;

            while(have==need)
            {
                if(right-left+1 < res)
                {
                    res = right-left+1;
                    first = left;
                    last = right;
                }

                char temp = s[left];
                smap[temp] -= 1;
                if(smap[temp] <  tmap[temp])
                    have--;
                left++;
            }

            right++;

        }

        return res==INT_MAX?"":s.substr(first,last-first+1);
    }
};
