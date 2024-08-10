//problem: https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0, high=arr.size(),mid;
        
        if(arr.size()==0)
            return -1;
        
        if(arr.size()==1)
            return 0; 
        
        while(low<high)
        {
            mid = low + (high-low)/2;
            
            if(mid-1 >=0 && mid+1<arr.size() && arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            
            if(arr[mid]<arr[mid+1])
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
};
