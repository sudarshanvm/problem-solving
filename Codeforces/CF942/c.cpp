#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxPermutationSubarrays(int n, long long k, vector<long long>& a) {
    long long maxSubarrays = 0;

    // Calculate the maximum possible number of subarrays of length n
    long long maxPossibleSubarrays = (n * (n + 1)) / 2;

    // Calculate the number of subarrays of length n which are a permutation of [1,2,…,𝑛]
    for (int i = 0; i < n; ++i) {
        long long subarrays = min(a[i], k);
        maxSubarrays += (subarrays * (subarrays + 1)) / 2;
        k -= subarrays;
        if (k <= 0) break;
    }

    // Calculate the number of additional cards needed to maximize the number of subarrays
    long long additionalCards = max(0LL, maxPossibleSubarrays - maxSubarrays);

    // Return the minimum of the maximum possible number of subarrays and the number of additional cards
    return maxSubarrays + min(k, additionalCards);
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        long long k;
        cin >> n >> k; // Number of distinct types of cards and number of coins

        vector<long long> a(n); // Number of cards of each type
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << maxPermutationSubarrays(n, k, a) << endl;
    }

    return 0;
}
