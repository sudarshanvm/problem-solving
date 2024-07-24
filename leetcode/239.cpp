//problem : https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:

    // void print(deque<int>d, int l, int r)
    // {
    //     cout<<"Deque L= "<<l<<" R= "<<r<<" : ";
    //     for(auto q:d)
    //         cout<<q<<" <-> ";
    //     cout<<endl;
    // }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;

        int l=0,r=0;
        while(r<nums.size())
        {
            while(!dq.empty() && nums[r] > dq.back())
                dq.pop_back();

            dq.push_back(nums[r]);
            // print(dq,l,r);
            if(r-l+1 < k)
                r++;
            else if(r-l+1 == k)
            {
                res.push_back(dq.front());
                if(dq.front() == nums[l])
                    dq.pop_front();

                l++;
                r++;
            
            }
        }

        return res;
    }
};