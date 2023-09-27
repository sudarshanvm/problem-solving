//problem: https://leetcode.com/problems/one-edit-distance/description/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ssize=s.size(), tsize=t.size();
        int diff = ssize-tsize;
        if(abs(diff)>1)
            return false;
        if(s==t)
            return false;

        for(int i=0;i<min(ssize,tsize);i++)
        {
            if(s[i]!=t[i])
            {
                // if s.size() == t.size(), only replace is allowed
                if(ssize==tsize)
                    return s.substr(i+1) == t.substr(i+1);
                
                // if s.size() < t.size(), delete from t allowed
                if(ssize<tsize)
                    return s.substr(i) == t.substr(i+1);

                // if s.size() > t.size(), delete from s allowed
                if(ssize>tsize)
                    return s.substr(i+1) == t.substr(i);

            }
        }
        return true;
    }
};
