//problem: https://leetcode.com/problems/largest-component-size-by-common-factor/description/

class UnionFind
{
    private:
        vector<int>root;
        vector<int>rank;
    public:
        
        UnionFind(int n)
        {
            for(int i=0;i<n;i++)
            {
                root.push_back(i);
                rank.push_back(1);
            }
        }

        int find(int x)
        {
            if(x==root[x])
                return x;
            return root[x]=find(root[x]);
        }

        void unionSet(int x, int y)
        {
            int rx = find(x);
            int ry = find(y);

            if(rx!=ry)
            {
                if(rank[rx]>rank[ry])
                    root[ry]=rx;
                else if(rank[rx]<rank[ry])
                    root[rx]=ry;
                else
                {
                    root[ry]=rx;
                    rank[rx]+=1;
                }
            }
        }

        bool connected(int x, int y)
        {
            return find(x)==find(y);
        }
};

class Solution {
public:


    int largestComponentSize(vector<int>& nums) {
        //construct a graph by checking gcd of two numbers
        int n = 1e5+1;
        UnionFind uf(n);

        //union each num with its factors
        for(int i=0;i<nums.size();i++)
        {
            for(int j=2;j<=sqrt(nums[i]);j++)
            {
                if(nums[i]%j==0)
                {
                    uf.unionSet(nums[i],j);
                    uf.unionSet(nums[i],nums[i]/j);
                }
            }
        }


        //get size of each component and find max component size
        unordered_map<int,int> m;
        int res=0;
        for(auto num:nums)
        {
            int root = uf.find(num);
            m[root]++;
            res = max(res, m[root]);
        }
            
        return res;

    }
};
