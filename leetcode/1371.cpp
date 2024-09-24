// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> seen;
        seen[0]=-1;
        int bitmask=0;
        int res=0;

        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='a') bitmask = bitmask ^ 1<<0;
            if(ch=='e') bitmask = bitmask ^ 1<<1;
            if(ch=='i') bitmask = bitmask ^ 1<<2;
            if(ch=='o') bitmask = bitmask ^ 1<<3;
            if(ch=='u') bitmask = bitmask ^ 1<<4;

            if(seen.find(bitmask)!=seen.end())
                res= max(res,i-seen[bitmask]);
            else
                seen[bitmask]=i;
        }

        return res;
    }
};
