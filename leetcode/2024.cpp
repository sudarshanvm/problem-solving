//problem: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/?source=submission-noac

class Solution {
public:

    int solve(string a,int k,int n, char c)
    {
        int res=0;
        int count=0;
        int left=0, right=0;
        while(right<n)
        {
            cout<<right<<"right"<<endl;
            count += (a[right]!=c);
            if(count>k)
            {
                while(a[left]==c)
                    left++;
                left++;
                count--;
            }
            right++;
            res=max(res,right-left);
        }

        return res;
    }

    int maxConsecutiveAnswers(string a, int k) {
        //calc max window size in two ccases: 1. replace Ts with Fs 2. replace Fs with Ts
        // each window should contain less than or equal to k Fs or Ts
        int n=a.size();
        int res1=solve(a,k,n,'T');
        int res2=solve(a,k,n,'F');
        return max(res1,res2);
    }
};