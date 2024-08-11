//problem: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
class Solution {
public:

    string generate(string s, bool one)
    {
        int n = s.size();
        string s1;
        for(int i=0;i<n;i++)
        {
            if(one)
            {    
                s1 += "1";
                one = false;
            }
            else
            {
                s1 += "0";
                one = true;
            }
        }

        return s1;
    }

    int minFlips(string s) {
        int n = s.size(), res = INT_MAX;

        s += s;

        string s1, s2;
        
        s1 = generate(s,true); cout<<"s1: "<<s1<<endl;
        s2 = generate(s,false); cout<<"s2: "<<s2<<endl;

        int left = 0, right = 0, d1=0, d2=0;
        while(right<s.size())
        {
            d1 += (s1[right] != s[right])?1:0;
            d2 += (s2[right] != s[right])?1:0;

            if(right>=n)
            {
                d1 -= (s1[left] != s[left])?1:0;
                d2 -= (s2[left] != s[left])?1:0;
                res = min(res, min(d1,d2));
                left++;
            }
         
            right++;
        }
        
        return res;
    }
};



