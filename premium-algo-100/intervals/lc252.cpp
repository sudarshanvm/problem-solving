//problem : https://leetcode.com/problems/meeting-rooms/

bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[1]<b[1];
    }

class Solution {
public:
    

    bool canAttendMeetings(vector<vector<int>>& intervals) {
            
        if(intervals.size()<=1)
            return true;

        sort(intervals.begin(), intervals.end(), compare);

        for(int i=0;i<intervals.size()-1;i++)
        {
            vector<int> temp1 = intervals[i];
            vector<int> temp2 = intervals[i+1];

            if(temp1[1]>temp2[0])
                return false;
        }
        return true;
    }
};
