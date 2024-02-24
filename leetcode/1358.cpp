//problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
class Solution {
public:

    int solve(string s, int start, int end)
    {
        return end-start+1;
    }

    int numberOfSubstrings(string s) {
        

        int res=0,n=s.size();
        int count[130]={0};
        count[s[0]-'a']=1;
        int left=0;
        for(int i=1;i<n;i++)
        {
           count[s[i]-'a']++;
           
            cout<<count[0]<<"-"<<count[1]<<"-"<<count[2]<<endl;
            while((count[0]>0)&&(count[1]>0)&&(count[2]>0))
             {   res += (n-i);
                
                    count[s[left++]-'a']--;
             }
        }

        return res;
    }
};