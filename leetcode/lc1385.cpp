class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for(auto num : arr1)
        {

            bool flag = true;
            for(auto num2 : arr2)
            {
                if(abs(num-num2)<=d)
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
                count++;
        }

        return count;
    }
};