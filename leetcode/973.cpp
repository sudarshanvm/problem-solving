//problem: https://leetcode.com/problems/k-closest-points-to-origin/
typedef pair<int,int> pi;
typedef pair<double,pi> pip;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pip, vector<pip>, greater<pip> >pq;
        vector<vector<int> > res;
        for(auto point: points)
        {
            int sq = (point[0]-0)*(point[0]-0) + (point[1]-0)*(point[1]-0);
            double dist = sqrt(sq);
            cout<<"DIST: "<<(double)dist<<" POINTS: "<<point[0]<<","<<point[1]<<endl;
            pi p = {point[0],point[1]};
            pip temp = {dist,p};
            pq.push(temp);
        }

        while(k--&&!pq.empty())
        {
            pip top = pq.top();
            pi ts = top.second;
            vector<int> temp= {ts.first, ts.second};
            res.push_back(temp);
            pq.pop();
        }

        return res;
    }
};
