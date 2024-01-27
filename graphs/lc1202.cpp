//problem: https://leetcode.com/problems/smallest-string-with-swaps/

class UnionFind
{
    private:
        vector<int> root;
    public:
        UnionFind(int n)
        {
            for(int i=0; i<n; i++)
            {
                root.push_back(i);
            }
        }
    
        int find(int x)
        {
            if(x==root[x])
                return x;
            return root[x]=find(root[x]);
        }
    
        void unionSet(int x, int y)
        {
            int rx = find(x);
            int ry = find(y);
            
            if(rx != ry)
            {
                root[ry] = rx;
            }
        }
    
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for(auto pair: pairs)
        {
            int x = pair[0];
            int y = pair[1];
            uf.unionSet(x,y);
        }

        string res(s.length(), ' ');
        unordered_map<int, vector<int> > rtc;
        for(int i=0;i<s.size();i++)
        {
            rtc[uf.find(i)].push_back(i);
        }

        for(auto comp: rtc)
        {
            //sort each component and merge in resulting string
            vector<int> indices = comp.second;
            vector<char> characters;
            for (int index : indices) {
                characters.push_back(s[index]);
                cout<<s[index];
            }
            cout<<"-";
            sort(characters.begin(), characters.end());
            
            // Store the sorted characters
            for (int index = 0; index < indices.size(); index++) {
                res[indices[index]] = characters[index];
        }
        }
        
        return res;
    }
};
