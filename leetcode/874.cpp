// problem: https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int res = 0;
        int x = 0, y = 0;
        int face = 0; // 0: North, 1: East, 2: South, 3: West

        const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        set<pair<int, int>> obs;
        for (const auto& obstacle : obstacles) {
            obs.insert({obstacle[0], obstacle[1]});
        }

        for (int command : commands) {
            if (command == -1) {
                face = (face + 1) % 4; // Turn right
            } else if (command == -2) {
                face = (face + 3) % 4; // Turn left
            } else {
                int k = command;
                for(int i=1; i<=k; i++){
                    int newX = x+dir[face].first;
                    int newY = y+dir[face].second;
                    
                    pair<int,int> key = {newX,newY};
                    if(obs.find(key)!=obs.end()){
                        // obstacle has been found so don't go there
                        break;
                    }
                    x = newX, y=newY;
                    res = max(res, x*x+y*y);
                }
            }
        }

        return res;
    }
};

