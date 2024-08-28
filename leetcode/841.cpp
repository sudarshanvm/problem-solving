// problem: https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    void dfs(int x, vector<vector<int>>& rooms, set<int> &keys, vector<bool> &vis)
    {
        if(x<0 || x >= rooms.size())
            return;

        vis[x]=true;
        for(auto room: rooms[x])
            keys.insert(room);

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        set<int> keys;
        keys.insert(0);
        vector<bool> vis(n,0);
        while(!keys.empty())
        {

            int top = *keys.begin();
            if(vis[top])
            {
                keys.erase(top);
                continue;
            }
            dfs(top,rooms, keys, vis);
            keys.erase(top);
            for(auto key: keys)
                cout<<key<<"-";
        }


        for(int i=0;i<n;i++)
            if(!vis[i])
                return false;

        return true;
           
        
    }
};
