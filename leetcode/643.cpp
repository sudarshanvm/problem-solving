class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;
        int sum = 0;
        for(int i=0;i<k;i++)
            sum += nums[i];
        res = (double)sum / k;
        cout<<"SUM : "<<sum<<endl;
        double temp;
        int left=0;
        for(int i=k;i<nums.size();i++)
        {
            sum -= nums[left++];
            sum += nums[i];
            cout<<"SUM : "<<sum;
            temp = (double)sum/k;
            cout<<" TEMP : "<<temp<<endl;
            res = max(res,temp);
        }
        return res;
    }
};