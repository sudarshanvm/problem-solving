#include <iostream>
#include <algorithm>
#include <fstream>
#include<cmath>
using namespace std;

int countOrderedPairs(int n, int m) {
    int count = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= m; ++b) {
            if ((a + b) % (b * __gcd(a, b)) == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, m;
        cin >> n >> m; // Read n and m for the current test case
        cout << countOrderedPairs(n, m) << endl; // Output the count of ordered pairs
    }

    return 0;
}
