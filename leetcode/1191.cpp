// https://leetcode.com/problems/k-concatenation-maximum-sum/
class Solution {
public:
    long long kadane(vector<int> a)
    {
        long long sum=INT_MIN;
        long long max_sum=0;
        long long mod = 1e9+7;
        for(int i=0;i<a.size();i++)
        {
            if(sum<0)
                sum=a[i];
            else
                sum=sum+a[i];
            
            if(sum>max_sum)
            {
                max_sum=sum;
            }
        }

        return max_sum;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(arr.size()==0)  return 0;
        long long mod=1e9+7;
        long long single_max = kadane(arr);
        long long total_sum = 0;
        long long prefix_sum=0,suffix_sum=0,max_prefix_sum=0,max_suffix_sum=0;
        for (int num : arr) {
            total_sum += num;
            prefix_sum += num;
            max_prefix_sum = max(max_prefix_sum, prefix_sum);
        }

        for (int i = arr.size() - 1; i >= 0; --i) {
            suffix_sum += arr[i];
            max_suffix_sum = max(max_suffix_sum, suffix_sum);
        }

        if (k == 1) {
            return single_max % mod;
        }

        // Case when k > 1
        long long result = max(single_max, max_suffix_sum + max_prefix_sum);
        if (total_sum > 0) {
            result = max(result, max_suffix_sum + max_prefix_sum + (k - 2) * total_sum);
        }

        return result % mod;
    }
};
