// problem: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
class Solution {
public:
    int getLucky(string s, int k) {
        string res;
        for(auto ch:s)
        {
            int num = ch - 'a' + 1;
            res += to_string(num);
        }

        int sum=0;
        for(auto ch: res)
            sum += int(ch-'a');

        while(k--)
        {
            sum = 0;
            for(auto ch: res)
            {    
                sum += ch-'0';
            }

            res = to_string(sum);
            cout<<res<<endl;
        }

        return sum;

    }
};
