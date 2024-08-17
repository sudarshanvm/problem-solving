//problem: https://leetcode.com/contest/biweekly-contest-85/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if(k > blocks.size())
            return -1;

        int countt = count(blocks.begin(), blocks.begin()+k, 'W');
        int n = blocks.size();


        int ans=countt;
        for(int i=k;i<n;i++)
        {
            countt += blocks[i]=='W';
            countt -= blocks[i-k]=='W';

            ans = min(ans,countt);
        }

        return ans;
        
    }
};
