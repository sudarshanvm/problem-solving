// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/?envType=problem-list-v2&envId=string-matching
// kmp algorithm (ref:
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
class Solution {
public:
    vector<int> computeLPS(string pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else
                    len = lps[len - 1];
            }
        }

        return lps;
    }

    vector<int> KMPSearch(string pat, string txt) {
        int m = pat.size(), n = txt.size();
        vector<int> res;
        if (m > n)
            return res;

        vector<int> lps = computeLPS(pat);
        int i = 0, j = 0;
        while ((n - i) >= (m - j)) {
            if (txt[i] == pat[j]) {
                j++;
                i++;
            }

            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            } else if (txt[i] != pat[j]) {
                if (j == 0)
                    i++;
                else {
                    j = lps[j - 1];
                }
            }
        }
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> a_indices = KMPSearch(a, s);
        vector<int> b_indices = KMPSearch(b, s);
        vector<int> res;
        sort(b_indices.begin(), b_indices.end());
        for (int i = 0; i < a_indices.size(); i++) {
            auto low = lower_bound(b_indices.begin(), b_indices.end(),
                                   a_indices[i] - k);
            if (low != b_indices.end() && abs(a_indices[i] - *low) <= k)
                res.push_back(a_indices[i]);
        }
        return res;
    }
};
