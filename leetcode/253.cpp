//problem : https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int count=0, ends_i=0;
        if(intervals.size()<2)
            return intervals.size();
        
        int n = intervals.size();
        int s[n], e[n];

        for(int i=0;i<n;i++)
        {
            vector<int> temp= intervals[i];
            s[i]=temp[0];
            e[i]=temp[1];
        }

        sort(s, s+n);
        sort(e, e+n);


        for(int i=0;i<n;i++)
        {
            if(s[i]<e[ends_i])
                count++;
            else
                ends_i++;
        }

        return count;
    }
};
