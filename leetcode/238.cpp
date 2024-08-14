class Solution {
public:
    vector<int> calcPrefixProduct(vector<int>& a)
    {
        vector<int>p(a.size());
        p[0]=1;
        for(int i=1;i<a.size();i++)
            p[i]=p[i-1]*a[i-1];
        return p;
    }
    
    vector<int> reverse(vector<int>& a)
    {
        vector<int>b(a.size());
        for(int i=0;i<a.size();i++)
            b[a.size()-i-1]=a[i];
        return b;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        // vector<int>r = reverse(nums);
        vector<int>res = calcPrefixProduct(nums);
        // vector<int>suffix_r = calcPrefixProduct(r);
        // vector<int>suffix = reverse(suffix_r);
        // vector<int>res(nums.size());
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            // res[i]=prefix[i]*suffix[i];
            // cout<<res[i]<<"="<<prefix[i]<<"x"<<suffix[i]<<endl;
            res[i]=product*res[i];
            product*=nums[i];
        }
        
        return res;
    }
};
