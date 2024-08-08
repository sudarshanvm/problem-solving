//problem: https://leetcode.com/problems/happy-number/
class Solution {
public:

    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            totalSum += digit * digit;
        }
        return totalSum;
    }
    
    bool isHappy(int n) {
        unordered_map<int,bool>m;
        while(n>0 && m.find(n)==m.end())
        {
            m[n] = true;
            n = getNext(n);
        }

        return n==1;
    }
};
