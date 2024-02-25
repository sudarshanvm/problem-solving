//problem: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
class Solution {
public:

    //sliding window
    int maxVowels(string s, int k) {
        unordered_map<char,int>m;
        m['a']=1;
        m['e']=1;
        m['i']=1;
        m['o']=1;
        m['u']=1;

        int n=s.size();
        int count=0,res=0;

        int left=0,right=0;
        int vowels=0;
        while(right<n)
        {
            char c = s[right];
            if(m[c])
                vowels++;
            count++;
                
            while(count>k)
            {
                if(m[s[left++]])
                    vowels--;
                count--;
            }
            // cout<<"start:"<<left<<" end:"<<right<<" vowels:"<<vowels<<endl;
            res=max(res,vowels);
            right++;
        }
        return res;
    }

    //brute force
    // int maxVowels(string s, int k) {
    //     unordered_map<char,int>m;
    //     m['a']=1;
    //     m['e']=1;
    //     m['i']=1;
    //     m['o']=1;
    //     m['u']=1;

    //     int n=s.size();
    //     int count=0,res=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int vowels=0,count=0;
    //         for(int j=i;j<n;j++)
    //         {
    //             count++;
    //             char c = s[j];
    //             if(m[c])
    //                 vowels++;
    //             if(count==k)
    //                 res=max(res,vowels);
    //         }
    //     }
    //     return res;
    // }
};