
// Rabin Karp algorithm (rolling hash based)
// Ref: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// time complexity: O(n+m) Avg Case, O(n*m)
// space complexity: O(1)

vector<int> rabinKarp(string txt, string pat) {
    // returns an array of indices where pat is matching with txt
  
    int m = pat.size(), n = txt.size();
    vector<int> indices;
    if (m > n)
        return {};

    long long d = 26;
    long long mod = 1e9 + 7;
    long long p = 0, t = 0, h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % mod;

    for (int i = 0; i < m; i++) {
        p = (p * d + pat[i]) % mod;
        t = (t * d + txt[i]) % mod;
    }

    int i, j;
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (pat[j] != txt[i + j])
                    break;
            }
            if (j == m)
                indices.push_back(i);
        }
        if (i < n - m) {
            long long t_ = (t - txt[i] * h) % mod;
            t = (t_ * d + txt[i + m]) % mod;
            if (t < 0)
                t += mod;
        }
    }
    return indices;
}

// example problem: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/