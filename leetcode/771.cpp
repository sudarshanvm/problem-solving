//problem: https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char,int> count;
        for(auto stone: stones)
            count[stone]++;

        int res = 0;
        for(auto jewel: jewels)
            if(count.find(jewel)==count.end())
                continue;
            else
                res += count[jewel];

        return res;
        
    }
};
