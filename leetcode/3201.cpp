//problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n1=0,n2=1,n3=1,n4=0;
       
        
        int l=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2==0)  // 1- even, even, even, ..
                n1++;
            else // 4- odd, odd, odd, ..
                n4++;
        }

        int res1 = max(n1, n4);

        

        bool odd = true;
        bool even = true;

        int o=0; // 2- odd, even, odd, .. 
        while(o<nums.size()&&nums[o]%2!=1)
            o++;

        for(int i=o; i<nums.size();i++)
        {
            int rem = nums[i]%2;
            if(odd && rem==0)
            {    n2++; odd=false;}
            else if(!odd && rem==1)
             {   n2++; odd=true;}

        }

        int e=0; // 2- even, odd, even, ..
        while(e<nums.size()&&nums[e]%2!=0)
            e++;
        for(int i=e; i<nums.size();i++)
        {
            int rem = nums[i]%2;
            if(even && rem==1)
            {    n3++; even=false;}
            else if(!even && rem==0)
             {   n3++; even=true;}

        }

        int res2 = max(n2, n3);
        cout<<n1<<" "<<n4<<" "<<n2<<" "<<n3<<endl;
        return max(res1, res2);
    }
};
