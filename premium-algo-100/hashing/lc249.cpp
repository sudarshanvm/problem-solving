//problem : https://leetcode.com/problems/group-shifted-strings/

class Solution {
public:

    string shift(string s)
    {
        string res="";
        for(int i=1;i<s.size();i++)
        {
            int diff=s[i]-s[i-1];
            if(diff<0)
                diff+=26;
            res+=to_string(diff)+",";
        }
        cout<<res<<endl;
        return res;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>>m;
        for(int i=0;i<strings.size();i++)
        {
            string word = strings[i];
            m[shift(word)].push_back(word);
        }

        vector<vector<string>>res;
        for(auto i:m)
        {
            vector<string> temp = i.second;
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }

};
