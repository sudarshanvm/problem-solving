//problem: https://leetcode.com/problems/first-unique-number/

class FirstUnique {
public:
    queue<int>q;
    unordered_map<long,int>h;
    FirstUnique(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
            {
                h[nums[i]]++;
                q.push(nums[i]);
            }
        
    }
    
    int showFirstUnique() {

        while(!q.empty()&&h[q.front()]>1)
            q.pop();

        if(q.empty())
            return -1;
            
        return q.front();
    }
    
    void add(int value) {
        q.push(value);
        h[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */


//-------------------------------------------------------------------
//optimise 1 
//still TLE
//problem: https://leetcode.com/problems/first-unique-number/

class FirstUnique {
public:
    vector<int>q;
    unordered_map<long,int>h;
    FirstUnique(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
            h[nums[i]]++;
        q=nums;
    }
    
    int showFirstUnique() {

        for(auto i:q)
        {
            if(h[i]==1)
                return i;
        }
            
        return -1;
    }
    
    void add(int value) {
        q.push_back(value);
        h[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */


//-------------------------------------------------------------------------

//problem: https://leetcode.com/problems/first-unique-number/
//hits TLE
class FirstUnique {
public:
    queue<int>q;
    int h[100001]={0};
    FirstUnique(vector<int>& nums) {
        
        
        for(int i=0;i<nums.size();i++)
            h[nums[i]]++;
        for(auto i:nums)
            q.push(i);
    }
    
    int showFirstUnique() {
        queue<int>copy = q;
        while(!copy.empty())
        {
            int i = copy.front();
            if(h[i]==1)
                return i;
            copy.pop();
        }
            
        return -1;
    }
    
    void add(int value) {
        q.push(value);
        h[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
