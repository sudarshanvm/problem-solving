//problem: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int sum=0;
        float avg;
        for(int i=0;i<k;i++)
            sum += arr[i];

        avg=sum/k;
        int count=avg>=threshold?1:0;
        for(int i=k;i<arr.size();i++)
        {
            sum = sum + arr[i] - arr[i-k];
            avg = sum/k;
            if(avg>=threshold)
                count++;
        }

        return count;
    }
};