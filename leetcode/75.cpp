//problem: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i] > a[j])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        return;
    }
};
