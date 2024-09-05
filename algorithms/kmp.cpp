// kmp algorithm (ref:
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
// time complexity: O(n+m)
// space complexity: O(m)
   
vector<int> computeLPS(string pat) {
    // computes and returns LPS array (LPS: Longest prefix which is also a suffix)
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
    // returns an array of indices where pattern is matching in the given text
    // time complexity: O(n+m)
    // space complexity: O(m)

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

// example problem: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/?envType=problem-list-v2&envId=string-matching
