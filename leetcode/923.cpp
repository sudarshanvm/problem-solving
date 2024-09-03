// problem: https://leetcode.com/problems/3sum-with-multiplicity/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int > m;
        long long mod = 1e9 + 7;
        long long count = 0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int need = target-arr[j]-arr[i];
                count = (count+m[need])%mod;
            }

            m[arr[i]]++;
        }

        return count;
    }
};

