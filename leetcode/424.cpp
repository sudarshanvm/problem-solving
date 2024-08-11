//problem: https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:

    int gethf(unordered_map<char,int> m)
    {
        int res = 0;
        for(auto item: m)
            res = max(res, item.second);

        return res;
    }

    int characterReplacement(string s, int k) {

        int left=0, right=0, res=0, n = s.size();

        int hf=0;
        unordered_map<char,int> m;

        while(right<n)
        {
            char cur = s[right];
            m[cur] += 1;
            hf = gethf(m);
            cout<<hf<<endl;
            
            if(right-left+1 > k+hf)
            {
                char temp = s[left];
                m[temp] -= 1;
                left++;
            }
            
            res = max(res, right-left+1);

            right++;
        }

        return res;
    }
};

