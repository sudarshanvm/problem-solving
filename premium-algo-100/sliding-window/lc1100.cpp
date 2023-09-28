// problem : https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/

class Solution {
public:

    bool anyDuplicates(string s, int * a, int start, int end)
    {
        for(int i=start;i<end;i++)
            if(a[s[i]]>1)
                return true;

        return false;
    }


    int numKLenSubstrNoRepeats(string s, int k) {
        int a[128] = {0};
        int left=0, count=0;

        if(s.size()<k)
            return 0;

        for(int i=0;i<k;i++)
            a[s[i]]++;
        
        if(!anyDuplicates(s,a,0,k))
            count++;

        for(int i=k;i<s.size();i++)
        {
            a[s[i]]++;
            a[s[left++]]--;
            if(!anyDuplicates(s,a,left,i))
                count++;
        }

        return count;
    }
};
