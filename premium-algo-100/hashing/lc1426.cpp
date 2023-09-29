//problem : https://leetcode.com/problems/counting-elements/
class Solution {
public:
    int countElements(vector<int>& arr) {
        int a[1002]={0};
        int res=0;
        for(auto i:arr)
            a[i]++;
        for(int i=0;i<arr.size();i++)
            if(a[arr[i]+1])
                res++;
        return res;
    }
};
