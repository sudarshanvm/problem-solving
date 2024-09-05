// problem:
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=problem-list-v2&envId=string-matching
// Rabin Karp implementation
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (n < m)
            return -1;

        int d = 26, mod = 11;

        int h = 1, p = 0, t = 0;

        for (int i = 0; i < m - 1; i++)
            h = (h * d) % mod;

        for (int i = 0; i < m; i++) {
            p = (p * d + needle[i]) % mod;
            t = (t * d + haystack[i]) % mod;
        }

        int i, j;
        for (i = 0; i <= n - m; i++) {
            if (p == t) {
                for (j = 0; j < m; j++)
                    if (haystack[i + j] != needle[j])
                        break;

                if (j == m)
                    return i;
            }
            if (i < n - m) {
                int t_ = t - haystack[i] * h;
                t = (t_ * d + haystack[i + m]) % mod;
                if (t < 0)
                    t += mod;
            }
        }
        return -1;
    }
};
