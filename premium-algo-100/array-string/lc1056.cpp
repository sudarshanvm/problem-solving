class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
        
    }

    bool confusingNumber(int n) {
        vector<int>b;
        int original_num = n;
        while(n>0)
        {
            b.push_back(n%10);
            n=n/10;
        }

        for(int i=0;i<b.size();i++)
        {
            if(b[i]==6)
                b[i]=9;
            else if(b[i]==9)
                b[i]=6;
        }
        int res=0;
        bool invalid=false;
        for(auto ele:b)
        {
            res = res * 10 + ele;
            if(ele==2||ele==3||ele==4||ele==5||ele==7)
                invalid=true;
        }
        if (res==original_num||invalid)
            return false;
        return true;

    }
};
