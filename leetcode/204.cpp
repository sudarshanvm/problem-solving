//problem: https://leetcode.com/problems/count-primes/submissions/1184311701/

class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool>isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(long long i=2;i<n;i++)
        {
            if(isprime[i])
            {
                count++;
                for(long long j=i*i;j<n;j+=i)
                    isprime[j]=false;
            }
        }
        return count;
    }
};
