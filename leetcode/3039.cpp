//https://leetcode.com/contest/biweekly-contest-124/problems/apply-operations-to-make-string-empty/
class Solution {
public:
    string remove(string s) {
        unordered_set<char> seen;
        string result;

        for (char c : s) {
            
            char lowercaseC = tolower(c); // Convert to lowercase
            if (seen.find(lowercaseC) != seen.end()) {
                result += c; // Add the character if it's the first occurrence
            }
            else
                seen.insert(lowercaseC);
            
        }

        return result;
    }
    
    string lastNonEmptyString(string s) {
        unordered_map<char, int> charCount;
        int mx=0;
        for (char c : s) {
            charCount[c]++;
            mx=max(mx,charCount[c]);
        }
        
        string res="";
        for(int i=s.size();i>=0;i--)
        {
            if(charCount[s[i]]==mx)
            {
                res = s[i] + res;
                charCount[s[i]]=0;
            }
        }
        return res;
        
    }
};