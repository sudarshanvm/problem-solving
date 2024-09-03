// problem: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int i=0;
        long long sum =0;
        for(auto c:chalk)
            sum += c;

        k = k%sum;
        while(chalk[i%chalk.size()]<=k)
        {
            k-=chalk[i%chalk.size()];
            i++;
        }

        return i%chalk.size();
    }
};
