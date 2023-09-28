//problem : https://leetcode.com/problems/palindrome-permutation/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int a[128]={0};
        for(int i=0;i<s.size();i++)
            a[s[i]]++;

        int count=0;
        for(int i=0;i<128;i++)
            if(a[i]%2==1)
                count++;

        return count<2;
    }
};
