//problem link: https://leetcode.com/problems/perform-string-shifts/description/

optimization:
class Solution {
public:

    string shiftHelper(string t, int amt, bool isLeft)
    {
        int n=t.size();
        string s = t;
        amt = amt % n;
        if(isLeft)
        {
            for(int i=0;i<s.size();i++)
                s[i] = t[(i+amt)%n];
        }
        else
        {
            for(int i=0;i<s.size();i++)
                s[i] = t[(n-amt+i)%n];
        }
        
        return s;
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        // if shift left i.e. 0 then s[i] = s[(i+1)%n]
        // if shift right i.e. 1 then s[i] = s[(i+n-1)%n]
        // optimization: compute overall left shift and overral right shift so that we need to do shift only two times 
        int leftshift=0, rightshift=0;
        for(auto a: shift)
        {
            if(a[0]==0) 
                leftshift+=a[1];
            else
                rightshift+=a[1];
        }

        s = shiftHelper(s,leftshift,true);
        s = shiftHelper(s,rightshift,false);

        return s;
    }
};

----------------------------------------------------------------------------------
class Solution {
public:

    string shiftHelper(string t, int amt, bool isLeft)
    {
        int n=t.size();
        string s = t;
        amt = amt % n;
        if(isLeft)
        {
            for(int i=0;i<s.size();i++)
                s[i] = t[(i+amt)%n];
        }
        else
        {
            for(int i=0;i<s.size();i++)
                s[i] = t[(n-amt+i)%n];
        }
        
        return s;
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        // if shift left i.e. 0 then s[i] = s[(i+1)%n]
        // if shift right i.e. 1 then s[i] = s[(i+n-1)%n]
        for(auto a: shift)
        {
            if(a[0]==0) 
                s = shiftHelper(s,a[1],true);
            else
                s = shiftHelper(s,a[1],false);
            cout<<s<<endl;
        }

        return s;
    }
};
