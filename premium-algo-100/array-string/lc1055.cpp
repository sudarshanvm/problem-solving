//problem : https://leetcode.com/problems/shortest-way-to-form-string/description/

class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char,bool>ispresent;
        for(auto s:source)
            ispresent[s]=true;
        for(int i=0;i<target.size();i++)
            if(ispresent.find(target[i])==NULL)
                return -1;

        int j=0,count=1;
        for(int i=0;i<target.size();i++,j++)
        {
            while(j<source.size()&&source[j]!=target[i])
                j++;
            if(j==source.size())
            {
                count++;
                j=-1;
                i--;
            }
        }
        return count;
    }
};
