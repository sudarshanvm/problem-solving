//problem: https://leetcode.com/problems/top-k-frequent-words/

typedef pair<string,int> pw;

struct compare
{
    bool operator()(pw a, pw b)
    {
        if(a.second < b.second)
            return true;
        
        if(a.second == b.second)
            return a.first > b.first;

        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> count;

        sort(words.begin(), words.end());
        for(auto word:words)
            count[word]++;

        priority_queue< pw, vector<pw>, compare > pq;
        for(auto c:count)
            pq.push(make_pair(c.first,c.second));

        vector<string> res;

        while(!pq.empty() && k--)
        {
            pw top = pq.top(); pq.pop();
            res.push_back(top.first);
        }


        return res;
    }
};
