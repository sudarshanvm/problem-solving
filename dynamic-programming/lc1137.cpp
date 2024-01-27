//problem: https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n<3)
            return 1;
        vector<int>res(n+1);
        res[0]=0;
        res[1]=1;
        res[2]=1;
        for(int i=3;i<=n;i++)
            res[i]=res[i-3]+res[i-2]+res[i-1];
        
        return res[n];
    }
};
