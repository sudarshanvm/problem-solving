//problem: https://leetcode.com/problems/reverse-words-in-a-string-ii/description/ 

class Solution {
public:

    void reverse(vector<char>&s, int start, int end)
    {
        while(start<end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }

    void reverseWords(vector<char>& s) {
       
        int last=0,j=0;
        for(int i=0;i<s.size();i++)
        {
            if(i==s.size()-1)
                reverse(s, last, i);
            else if(s[i]==' ')
            {
                //traverse back until a space or until i=0 and reverse the order of chars
                reverse(s, last, i-1);
                last = i+1;
            }
        }

        reverse(s,0,s.size()-1);

    }
};
