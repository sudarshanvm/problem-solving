// problem: https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/?envType=problem-list-v2&envId=string-matching
//  rabin karp (rolling hash)
typedef long long ll;
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        const int d = 26 , mod = 1e9 + 9;
        ll res = 0;
        unordered_map<ll, int> hash;
        
        for(string word : words) {
            ll prefix = 0, suffix = 0;
            ll h = 1;
            
            int n = word.size();
            for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
                prefix = (prefix + word[i] * h) % mod;
                h = (h * d) % mod;
                
                suffix = (suffix * d + word[j]) % mod;
                
                if(prefix == suffix && hash.find(prefix) != hash.end())
                    res += hash[prefix];
            }
            
            hash[prefix]++;
            // hash.insert(suffix);
        }
        
        return res;
    }
};
