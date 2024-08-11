//problem: https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        int res=1;

        while(!q.empty())
        {
            int qn = q.size();
            for(int i=0;i<qn;i++)
            {
                string cur = q.front();
                q.pop();

                if(cur==endWord)
                    return res;

                s.erase(cur);

                for(int j=0;j<cur.size();j++)
                {
                    char temp = cur[j];
                    for(int k=0;k<26;k++)
                    {
                        char c = 'a' + k;
                        cur[j] = c;

                        if(s.find(cur)!=s.end())
                            q.push(cur);
                    }

                    cur[j] = temp;
                }
            }

            res++;

        }

        return 0;
    }
};














//-----------------------------------------
//TLE

//problem: https://leetcode.com/problems/word-ladder/
typedef pair<int,int> pi;
class Solution {
public:

    int dist(string s1, string s2)
    {
        int count = 0, n = min(s1.size(),s2.size());
        for(int i=0;i<n;i++)
           if(s1[i] != s2[i])
            count++;

        return count;

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(),beginWord); 
        int n = wordList.size();
        vector<vector<int> > a(n);
        int tar = -1, res=1;
        for(int i=0;i<n;i++)
            if(wordList[i] == endWord)
            {
                tar = i;
                break;
            }

        if(tar == -1)
            return 0;

        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d = dist(wordList[i], wordList[j]);
                if(d<=1) //== or <=?
                {
                    a[i].push_back(j);
                    a[j].push_back(i)a;
                }
            }
        }

        queue<pi> q;
        int d=1;
        q.emplace(0,d);
        vector<bool>vis(n);
        vis[0]=true;
        while(!q.empty())
        {
            int f = q.front().first; 
            d = q.front().second;
            cout<<f<<"-"<<d<<": ";
            q.pop();
            vis[f]=true;

            if(f==tar)
                return d;

            for(auto node: a[f])
            {
                if(vis[node])
                    continue;
                cout<<"push "<<node<<" ";
                q.emplace(node,d+1);
            }
            cout<<endl;
        }

        return 0;

    }
};
